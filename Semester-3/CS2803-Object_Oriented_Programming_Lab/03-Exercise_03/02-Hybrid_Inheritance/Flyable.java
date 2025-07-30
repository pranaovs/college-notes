/*
 * An interface for objects that have the capability to fly.
 * It defines the essential methods for flight.
 */
public interface Flyable {

    // Interfaces can also have constants
    int MAX_ALTITUDE_FEET = 40000;

    // Abstract methods to be implemented by any class that is Flyable
    void takeOff();

    void land();

    void changeAltitude(int newAltitude);
}