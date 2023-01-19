// 2. 사각형 좌표 (-100,-50),(-100,100),(100,50),(50,-50)를 List로 설정하고, 중심 점을 계산한 후 출력하세요.
// class p2201811111RectangleMain ... ArrayList coords ... void setCoordinates(List coords) ... double[] getCenter()

import java.util.ArrayList;
import java.util.List;
public class RectangleMain {
	List<Double[]> coords = new ArrayList<Double[]>();
	double[] center = new double[2];
	void setCoordinates(List<Double[]> coords) {
		double sumX=0;
		double sumY=0;
		for(int i=0; i<coords.size(); i++) {
			sumX+=coords.get(i)[0];
			sumY+=coords.get(i)[1];
		}
		center[0]=sumX/coords.size();
		center[1]=sumY/coords.size();
	}
		double[] getCenter() {
		return this.center;
	}
		public static void main(String[] args) {

		Double[] p1 = {(double) -100,(double) -50};
		Double[] p2 = {(double) -100,(double) 100};
		Double[] p3 = {(double) 100,(double) 50};
		Double[] p4 = {(double) 50,(double) -50};

		RectangleMain r1 = new RectangleMain();
		r1.coords.add(p1);
		r1.coords.add(p2);
		r1.coords.add(p3);
		r1.coords.add(p4);
		r1.setCoordinates(r1.coords);
		System.out.printf("posX : %.2f, posY : %.2f",r1.getCenter()[0],r1.getCenter()[1]);

	}
}
