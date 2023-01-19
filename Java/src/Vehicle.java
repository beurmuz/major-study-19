// 3. 클래스 2개 p3201811111Vehicle.java, Sedan  • 인터페이스 Vehicle, 클래스 Sedan을 구현하세요.
// • power on/oﬀ에 따라 start(), stop()하고 changeSpeed() speed를 갱신.
// • start(), changeSpeed(), signalTurn(), stop() 출력 테스트하세요.
// • 출력은 “starting...”, “changing speed now at speed ??”, “turning...”, “stopping...

interface Vehicle {
	public void signalTurn(char direction, boolean signalOn);
	public void changeSpeed(int newSpeed);
	public void start();
	public void stop();
}
