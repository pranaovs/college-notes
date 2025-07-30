public class DistanceConverter {

    private double km_to_miles = 0.621371;
    private double km_to_meter = 1000;
    private double miles_to_meter = 1609.34;

    public double kmToMiles(double km) {
        return km * km_to_miles;
    }

    public double milesToKm(double miles) {
        return miles / km_to_miles;
    }

    public double meterToKM(double meter) {
        return meter * km_to_meter;
    }

    public double kmToMeter(double km) {
        return km / km_to_meter;
    }

    public double milesToMeter(double miles) {
        return miles * miles_to_meter;
    }

    public double meterToMiles(double meter) {
        return meter / miles_to_meter;
    }
}
