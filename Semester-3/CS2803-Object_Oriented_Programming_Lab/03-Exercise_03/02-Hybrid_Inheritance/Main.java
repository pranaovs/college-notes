
public class Main {
    public static void main(String[] args) {
        // Create an instance of our hybrid class
        FlyingCar myFlyingCar = new FlyingCar();

        // 'Vehicle' grandparent class
        myFlyingCar.setBrand("Flicar");

        // 'LandVehicle' parent class
        myFlyingCar.setNumberOfWheels(4);

        // Display initial status
        myFlyingCar.displayStatus();

        // Behavior from 'LandVehicle' class
        myFlyingCar.drive();

        System.out.println("\nStarting flight");

        // Methods from the 'Flyable' interface
        myFlyingCar.takeOff();
        myFlyingCar.changeAltitude(5000);

        myFlyingCar.land();

        myFlyingCar.displayStatus();
    }
}