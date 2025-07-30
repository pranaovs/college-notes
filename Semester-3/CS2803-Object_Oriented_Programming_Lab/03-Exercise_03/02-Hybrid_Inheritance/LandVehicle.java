/*
 * Represents vehicles that operate on land.
 * It inherits from Vehicle and adds the concept of wheels.
 */
public class LandVehicle extends Vehicle {
    private int numberOfWheels;

    public void setNumberOfWheels(int wheels) {
        this.numberOfWheels = wheels;
    }

    // A behavior specific to land vehicles
    public void drive() {
        System.out.println("The " + brand + " is driving on " + numberOfWheels + " wheels.");
    }
}