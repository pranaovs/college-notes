public class CurrencyConverter {
    private double dollar_to_inr = 87.23;
    private double euro_to_inr = 100.79;
    private double yen_to_inr = 0.59;

    double dollarToInr(double dollar) {
        return dollar * this.dollar_to_inr;
    }

    double inrToDollar(double inr) {
        return inr * this.dollar_to_inr;
    }

    double euroToInr(double euro) {
        return euro * this.euro_to_inr;
    }

    double inrToEuro(double inr) {
        return inr * this.euro_to_inr;
    }

    double yenToInr(double yen) {
        return yen * this.yen_to_inr;
    }

    double inrToYen(double inr) {
        return inr / this.yen_to_inr;
    }
}
