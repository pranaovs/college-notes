public class TimeConverter {
    public double hoursToMinutes(double hours) {
        return hours * 60;
    }

    public double minutesToHours(double minutes) {
        return minutes / 60;
    }

    public double hoursToSeconds(double hours) {
        return hours * 3600;
    }

    public double secondsToHours(double seconds) {
        return seconds / 3600;
    }

    public double minutesToSeconds(double minutes) {
        return minutes * 60;
    }

    public double secondsToMinutes(double seconds) {
        return seconds / 60;
    }
}