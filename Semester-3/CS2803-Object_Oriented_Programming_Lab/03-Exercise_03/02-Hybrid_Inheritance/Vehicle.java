/**
 * The base class for all vehicles.
 * It contains a brand name.
 */
public class Vehicle {
    protected String brand;

    public void setBrand(String brand) {
        this.brand = brand;
        System.out.println("Vehicle brand set to: " + this.brand);
    }

    public String getBrand() {
        return brand;
    }
}
