#include "../PiRacer/PiRacer.hpp"
#include "../Gamepad/ShanwanGamepad.hpp"

int main()
{
	// Ensure GPIO is initialized
	

	// Create instances
	PiRacer racer;
	ShanWanGamepad gamepad;

	while (true)
	{
		ShanWanGamepadInput input = gamepad.read_data();

		float steering = input.analog_stick_left.x;
		float throttle = input.analog_stick_right.y * 0.5; // limit throtle to 50%

		std::cout << "Throttle: " << throttle
				<< ", Steering: " << steering
				<< std::endl;
		
		racer.setSteeringPercent(steering);
		racer.setThrottlePercent(throttle);
	}

	return 0;
}