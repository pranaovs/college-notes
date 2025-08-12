public class Main {
  public static void main(String[] args) {
    // Create an Animal object
    Animal genericAnimal = new Animal("Generic Animal");
    System.out.println("Animal name: " + genericAnimal.getName());
    genericAnimal.makeSound();

    System.out.println();

    // Create a Dog object
    Dog myDog = new Dog("Buddy", "Golden Retriever");
    System.out.println("Dog name: " + myDog.getName());
    System.out.println("Dog breed: " + myDog.getBreed());
    myDog.makeSound(); // This calls the overridden method

    // Demonstrate polymorphism
    Animal polymorphicDog = new Dog("Max", "German Shepherd");
    polymorphicDog.makeSound(); // This calls the overridden method
  }
}
