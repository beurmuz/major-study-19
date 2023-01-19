class Sedan implements Vehicle{
	boolean power;
	int speed;
	char i = 'i';

	@Override
	public void signalTurn(char direction, boolean signalOn) {
		if(signalOn==true&&direction=='l') {
			System.out.println("turning left");
		}
		else if(signalOn==true&&direction=='r') {
			System.out.println("turning right");
		}
		else if(signalOn==false) {
			System.out.println("System off");
		}
	}

	@Override
	public void changeSpeed(int newSpeed) {
		this.speed=newSpeed;
		System.out.println("changing speed now at speed "+this.speed);
	}

	@Override
	public void start() {
		this.power=true;
		System.out.println("Starting...");
	}

	@Override
	public void stop() {
		this.power=false;
		System.out.println("Stopping...");
	}

		public static void main(String[] args) {
		Sedan s1 = new Sedan();
		s1.signalTurn('r', s1.power);
		s1.start();
		s1.signalTurn('l', s1.power);
		s1.changeSpeed(100);
		s1.signalTurn('r', s1.power);
		s1.changeSpeed(150);
		s1.stop();
	}
}
