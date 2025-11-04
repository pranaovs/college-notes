import javax.swing.*;
import java.awt.*;
import java.awt.event.ActionListener;

public class ButtonPanel {
  private CalculatorFrame calculator;

  public ButtonPanel(CalculatorFrame calculator) {
    this.calculator = calculator;
  }

  public JPanel createDecimalPanel() {
    JPanel panel = new JPanel();
    panel.setLayout(new GridLayout(5, 4, 5, 5));
    panel.setBorder(BorderFactory.createEmptyBorder(10, 10, 10, 10));

    String[] buttons = {
        "C", "CE", "BS", "/",
        "7", "8", "9", "*",
        "4", "5", "6", "-",
        "1", "2", "3", "+",
        "±", "0", ".", "="
    };

    for (String buttonText : buttons) {
      JButton button = createButton(buttonText);
      panel.add(button);
    }

    return panel;
  }

  public JPanel createScientificPanel() {
    JPanel panel = new JPanel();
    panel.setLayout(new GridLayout(6, 4, 5, 5));
    panel.setBorder(BorderFactory.createEmptyBorder(10, 10, 10, 10));

    String[] buttons = {
        "C", "CE", "BS", "/",
        "sin", "cos", "tan", "*",
        "7", "8", "9", "-",
        "4", "5", "6", "+",
        "1", "2", "3", "^",
        "log", "ln", "sqrt", "=",
        "1/x", "x²", "±", "0",
        ".", "", "", ""
    };

    for (String buttonText : buttons) {
      if (buttonText.isEmpty()) {
        panel.add(new JLabel(""));
      } else {
        JButton button = createButton(buttonText);
        panel.add(button);
      }
    }

    return panel;
  }

  private JButton createButton(String text) {
    JButton button = new JButton(text);
    button.setFont(new Font("Arial", Font.BOLD, 18));
    button.setFocusPainted(false);

    if (text.matches("[0-9]")) {
      button.setBackground(new Color(240, 240, 240));
    } else if (text.equals("=")) {
      button.setBackground(new Color(100, 150, 255));
      button.setForeground(Color.WHITE);
    } else if (text.matches("[+\\-*/^]")) {
      button.setBackground(new Color(255, 180, 100));
    } else {
      button.setBackground(new Color(220, 220, 220));
    }

    ActionListener listener = e -> calculator.processInput(text);
    button.addActionListener(listener);

    return button;
  }
}
