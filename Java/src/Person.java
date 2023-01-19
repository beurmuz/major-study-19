public class Person{
  private String name=null;
  private float weight;
  public Person(String name) {
    this.name=name;
  }
  public String getName(){
    return name;
  }
  public void setWeight(float weight) {
    this.weight=weight;
  }
  public float getWeight() {
    return weight;
  }
  public static void main(String[] args) {
    Person p=new Person("Kim");
    p.setWeight((float)65.0);
    String myName=p.getName();
    System.out.println(p.getName()+" "+ p.getWeight() + "Kg");
  }
}
