import dynaroach as dr;
import sys


f = open ("config.txt")
a = f.readline().strip()
print a
d = dr.DynaRoach(sys.argv[1]);

d.configure_settings("0x0100") #THE ORANGE ONE
d.set_data_streaming(True);

oldMotor = 0;
print "second one"
d2 = dr.DynaRoach(sys.argv[2]);
while (1):
  z = open("out.txt")
  val = z.readline().strip()
  if len(val) != 0:
    motor = int(val)
    if motor != oldMotor:
      d2.set_motor_config(motor, motor)
      #d.set_motor_config(0, 0)
      oldMotor = motor
