public class CalculatorEngine {
  private double currentValue;
  private double storedValue;
  private String currentOperation;
  private boolean startNewNumber;
  private String displayText;

  public CalculatorEngine() {
    clear();
  }

  public String processInput(String input) {
    switch (input) {
      case "C":
        clear();
        break;
      case "CE":
        displayText = "0";
        startNewNumber = true;
        break;
      case "=":
        calculateResult();
        break;
      case "+":
      case "-":
      case "*":
      case "/":
      case "^":
        handleOperation(input);
        break;
      case "sin":
      case "cos":
      case "tan":
      case "log":
      case "ln":
      case "sqrt":
      case "1/x":
      case "x²":
        handleScientificFunction(input);
        break;
      case ".":
        handleDecimalPoint();
        break;
      case "±":
        handleSign();
        break;
      case "BS":
        handleBackspace();
        break;
      default:
        handleDigit(input);
        break;
    }
    return displayText;
  }

  private void clear() {
    currentValue = 0;
    storedValue = 0;
    currentOperation = "";
    startNewNumber = true;
    displayText = "0";
  }

  private void handleDigit(String digit) {
    if (startNewNumber) {
      displayText = digit;
      startNewNumber = false;
    } else {
      if (displayText.equals("0")) {
        displayText = digit;
      } else {
        displayText += digit;
      }
    }
  }

  private void handleDecimalPoint() {
    if (startNewNumber) {
      displayText = "0.";
      startNewNumber = false;
    } else if (!displayText.contains(".")) {
      displayText += ".";
    }
  }

  private void handleSign() {
    if (!displayText.equals("0")) {
      if (displayText.startsWith("-")) {
        displayText = displayText.substring(1);
      } else {
        displayText = "-" + displayText;
      }
    }
  }

  private void handleBackspace() {
    if (!startNewNumber && displayText.length() > 1) {
      displayText = displayText.substring(0, displayText.length() - 1);
    } else {
      displayText = "0";
      startNewNumber = true;
    }
  }

  private void handleOperation(String operation) {
    try {
      currentValue = Double.parseDouble(displayText);

      if (!currentOperation.isEmpty()) {
        calculateResult();
        currentValue = Double.parseDouble(displayText);
      }

      storedValue = currentValue;
      currentOperation = operation;
      startNewNumber = true;
    } catch (NumberFormatException e) {
      displayText = "Error";
      startNewNumber = true;
    }
  }

  private void calculateResult() {
    try {
      currentValue = Double.parseDouble(displayText);

      switch (currentOperation) {
        case "+":
          currentValue = storedValue + currentValue;
          break;
        case "-":
          currentValue = storedValue - currentValue;
          break;
        case "*":
          currentValue = storedValue * currentValue;
          break;
        case "/":
          if (currentValue == 0) {
            displayText = "Error";
            startNewNumber = true;
            currentOperation = "";
            return;
          }
          currentValue = storedValue / currentValue;
          break;
        case "^":
          currentValue = Math.pow(storedValue, currentValue);
          break;
      }

      displayText = formatResult(currentValue);
      currentOperation = "";
      startNewNumber = true;
    } catch (NumberFormatException e) {
      displayText = "Error";
      startNewNumber = true;
    }
  }

  private void handleScientificFunction(String function) {
    try {
      currentValue = Double.parseDouble(displayText);

      switch (function) {
        case "sin":
          currentValue = Math.sin(Math.toRadians(currentValue));
          break;
        case "cos":
          currentValue = Math.cos(Math.toRadians(currentValue));
          break;
        case "tan":
          currentValue = Math.tan(Math.toRadians(currentValue));
          break;
        case "log":
          if (currentValue <= 0) {
            displayText = "Error";
            startNewNumber = true;
            return;
          }
          currentValue = Math.log10(currentValue);
          break;
        case "ln":
          if (currentValue <= 0) {
            displayText = "Error";
            startNewNumber = true;
            return;
          }
          currentValue = Math.log(currentValue);
          break;
        case "sqrt":
          if (currentValue < 0) {
            displayText = "Error";
            startNewNumber = true;
            return;
          }
          currentValue = Math.sqrt(currentValue);
          break;
        case "1/x":
          if (currentValue == 0) {
            displayText = "Error";
            startNewNumber = true;
            return;
          }
          currentValue = 1.0 / currentValue;
          break;
        case "x²":
          currentValue = currentValue * currentValue;
          break;
      }

      displayText = formatResult(currentValue);
      startNewNumber = true;
    } catch (NumberFormatException e) {
      displayText = "Error";
      startNewNumber = true;
    }
  }

  private String formatResult(double value) {
    if (Double.isInfinite(value) || Double.isNaN(value)) {
      return "Error";
    }

    if (value == (long) value) {
      return String.format("%d", (long) value);
    } else {
      String result = String.format("%.10f", value);
      result = result.replaceAll("0*$", "").replaceAll("\\.$", "");
      return result;
    }
  }
}
