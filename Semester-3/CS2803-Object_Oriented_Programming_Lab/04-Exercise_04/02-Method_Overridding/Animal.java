public class Animal {
  private String name;

  public Animal(String name) {
    this.name = name;
  }

  public String getName() {
    return name;
  }

  public void makeSound() {
    System.out.println("Animal makes a generic sound");
  }
}
