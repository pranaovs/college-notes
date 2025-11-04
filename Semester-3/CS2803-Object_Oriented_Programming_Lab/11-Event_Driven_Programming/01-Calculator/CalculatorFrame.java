import javax.swing.*;
import java.awt.*;

public class CalculatorFrame extends JFrame {
  private JTextField display;
  private CalculatorEngine engine;
  private ButtonPanel buttonPanel;

  public CalculatorFrame() {
    engine = new CalculatorEngine();
    initializeUI();
  }

  private void initializeUI() {
    setTitle("Calculator");
    setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
    setLayout(new BorderLayout(5, 5));
    setResizable(false);

    display = new JTextField();
    display.setEditable(false);
    display.setFont(new Font("Arial", Font.BOLD, 24));
    display.setHorizontalAlignment(JTextField.RIGHT);
    display.setText("0");
    display.setPreferredSize(new Dimension(400, 60));
    add(display, BorderLayout.NORTH);

    JTabbedPane tabbedPane = new JTabbedPane();

    buttonPanel = new ButtonPanel(this);
    tabbedPane.addTab("Decimal", buttonPanel.createDecimalPanel());
    tabbedPane.addTab("Scientific", buttonPanel.createScientificPanel());

    add(tabbedPane, BorderLayout.CENTER);

    pack();
    setLocationRelativeTo(null);
  }

  public void processInput(String input) {
    String result = engine.processInput(input);
    display.setText(result);
  }

  public String getCurrentDisplay() {
    return display.getText();
  }
}
