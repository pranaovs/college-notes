import java.util.Random;

public class Main {
    private static Integer sharedNumber = null;
    private static final Object lock = new Object();

    public static void main(String[] args) {
        Thread generatorThread = new Thread(new NumberGenerator());
        Thread squareThread = new Thread(new SquareCalculator());
        Thread cubeThread = new Thread(new CubeCalculator());

        generatorThread.start();
        squareThread.start();
        cubeThread.start();
    }

    static class NumberGenerator implements Runnable {
        private Random random = new Random();

        @Override
        public void run() {
            while (true) {
                try {
                    Thread.sleep(1000);
                    synchronized (lock) {
                        sharedNumber = random.nextInt(100);
                        System.out.println("Generated: " + sharedNumber);
                        lock.notifyAll();
                    }
                } catch (InterruptedException e) {
                    e.printStackTrace();
                }
            }
        }
    }

    static class SquareCalculator implements Runnable {
        @Override
        public void run() {
            while (true) {
                try {
                    synchronized (lock) {
                        lock.wait();
                        if (sharedNumber != null && sharedNumber % 2 == 0) {
                            int square = sharedNumber * sharedNumber;
                            System.out.println("Square of " + sharedNumber + " = " + square);
                        }
                    }
                } catch (InterruptedException e) {
                    e.printStackTrace();
                }
            }
        }
    }

    static class CubeCalculator implements Runnable {
        @Override
        public void run() {
            while (true) {
                try {
                    synchronized (lock) {
                        lock.wait();
                        if (sharedNumber != null && sharedNumber % 2 != 0) {
                            int cube = sharedNumber * sharedNumber * sharedNumber;
                            System.out.println("Cube of " + sharedNumber + " = " + cube);
                        }
                    }
                } catch (InterruptedException e) {
                    e.printStackTrace();
                }
            }
        }
    }
}
