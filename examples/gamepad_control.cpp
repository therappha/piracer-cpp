#include "../PiRacer/PiRacer.hpp"
#include "../Gamepad/ShanwanGamepad.hpp"


int main()
{
	

	// Create instances
	PiRacer racer;
	ShanWanGamepad gamepad;

	while (true)
	{
		ShanWanGamepadInput input = gamepad.read_data();

		float steering = input.analog_stick_right.x;
		float throttle = input.analog_stick_right.y; // limit throttle to 100%

		std::cout << "Throttle: " << throttle
				<< ", Steering: " << steering
				<< std::endl;
		
		// racer.setSteeringPercent(steering);
		// racer.setThrottlePercent(throttle * 0.5);
		if (input.button_x) 
		{
			std::cout << "Exiting..." << std::endl;		
			break;
		}
		sleep(0.1);
	}
	// racer.setSteeringPercent(0.0);
	// racer.setThrottlePercent(0.0);

	return 0;
}