
public class CalculateMan{
public static int[][] data ={
    {74425, 76326},
    {61164, 61636},
    {109688, 115744},
    {144796, 146776},
    {174996, 181676},
    {177841, 177434},
    {204630, 205980},
    {223373, 232245},
    {161055, 166130},
    {171576, 176735},
    {279169, 293772},
    {239450, 251066},
    {148690, 156510},
    {182977, 196992},
    {237792, 242641},
    {283869, 296762},
    {209344, 210282},
    {118965, 114441},
    {186503, 186856},
    {195734, 203014},
    {254381, 249472},
    {212401, 229111},
    {271654, 295354},
    {319197, 335045},
    {229829, 231671}
};
int Msum=0;
int Fsum=0;
int everM=0;
int everF=0;
public void SumCalculate(){
  for(int i=0; i<25; i++){
    Msum+=data[i][0];
    Fsum+=data[i][1];
  }
  everM=Msum/25;
  everF=Fsum/25;
}public static void main(String[] args){
  CalculateMan a = new CalculateMan();
  a.SumCalculate();
  System.out.println("Male Sum : "+a.Msum);
  System.out.println("Female Sum : "+a.Fsum);
  System.out.println("Male everage : "+a.everM);
  System.out.println("Female everage : "+a.everF);
 }
}
