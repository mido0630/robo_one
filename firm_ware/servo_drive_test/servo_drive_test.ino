#include <Servo.h>
#include <ros.h>
#include <std_msgs/Int32.h>

//pin assign setting
#define INA 2
#define INB 3
#define SEL 10
#define CS A0
#define PWM 5

void set_motor_angle( const std_msgs::Int32& state);

ros::NodeHandle nh;
std_msgs::Int32 motor_state;
ros::Publisher pub_motor_state("motor_state", &motor_state);
ros::Subscriber<std_msgs::Int32> sub_motor_angle("motor_angle", set_motor_angle);
int target_angle=0;

void setup() {
  pinMode(INA, OUTPUT);
  pinMode(INB, OUTPUT);
  pinMode(SEL, OUTPUT);
  pinMode(CS, INPUT);
//  pinMode(PWM, OUTPUT);
  digitalWrite(INA,HIGH);
  digitalWrite(INB,LOW);
  digitalWrite(SEL,LOW);
  analogWrite(PWM,0);
  nh.initNode();
  nh.advertise(pub_motor_state);  
  nh.subscribe(sub_motor_angle);
  delay(1000);
}

void loop() {
  nh.spinOnce();
  motor_control();
  publish_motor_state();
  delay(10);
}

void motor_control(){
  delayMicroseconds(10);
  digitalWrite(INA,HIGH);
  digitalWrite(INB,LOW);
  analogWrite(PWM,target_angle);
  
}
void publish_motor_state(){
  motor_state.data=target_angle;
  pub_motor_state.publish(&motor_state);
}

void set_motor_angle(const std_msgs::Int32& angle) {
  target_angle = angle.data;
}
