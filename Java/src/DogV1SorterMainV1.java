//Sort = 정렬함수를 이용한 클래스

import java.util.Arrays;

public class DogV1SorterMainV1 {
    public static void main(String[] args){
        DogV1[] myDogs=new DogV1[3];
        myDogs[0]=new DogV1("d1","Poodle");
        myDogs[1]=new DogV1("d2","Husky");
        myDogs[2]=new DogV1("d3","Shih Tzu");
        Arrays.sort(myDogs);
        for(DogV1 d:myDogs)
            System.out.println(d.toString());
    }
}
