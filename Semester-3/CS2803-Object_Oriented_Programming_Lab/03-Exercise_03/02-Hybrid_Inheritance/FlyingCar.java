/*
 * The FlyingCar class demonstrates hybrid inheritance.
 * It extends LandVehicle, making it a type of land vehicle.
 * It implements Flyable, giving it the capability of flight.
 */
public class FlyingCar extends LandVehicle implements Flyable {

    private boolean isInFlightMode = false;

    // Implementing methods from the Flyable interface

    @Override
    public void takeOff() {
        System.out.println("Transitioning to flight mode... " + getBrand() + " is taking off!");
        isInFlightMode = true;
    }

    @Override
    public void land() {
        System.out.println("Preparing for landing... " + getBrand() + " has landed successfully.");
        isInFlightMode = false;
    }

    @Override
    public void changeAltitude(int newAltitude) {
        if (isInFlightMode) {
            System.out.println("Changing altitude to " + newAltitude + " feet.");
        } else {
            System.out.println("Cannot change altitude while on the ground.");
        }
    }

    // A method to display the overall status
    public void displayStatus() {
        System.out.println("\nFlying Car Status");
        System.out.println("Brand: " + getBrand()); // From Vehicle
        if (isInFlightMode) {
            System.out.println("Mode: In Flight");
        } else {
            System.out.println("Mode: Ground");
        }
    }
}