public class Dog extends Animal {
  private String breed;

  public Dog(String name, String breed) {
    super(name);
    this.breed = breed;
  }

  public String getBreed() {
    return breed;
  }

  @Override
  public void makeSound() {
    System.out.println("Dog barks: Woof! Woof!");
  }
}
