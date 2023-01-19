public class Tour{

  static String[] city = new String[5];

  public static void printCities(){
    city[0] = "Seoul";
    city[1] = "New York";
    city[2] = "Sydney";
    city[3] = "Tokyo";
    city[4] = "Beijing";

    for(int i=0; i<5; i++){
      System.out.printf("%s \n",city[i]);
    }
  }

  public static void main(String[]args){
    printCities();
  }
}
// 함수마다 static을 선언하면 메인함수 선언 시 객체와 생성자를 따로 선언하지 않아도 쓸 수 있음.
// 반면에 static을 선언하지 않으면 객체Tour t=new Tour하고 t.print~해야함.
