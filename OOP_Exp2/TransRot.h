#include <iostream>
#include <string>
#define _USE_MATH_DEFINES
#include <cmath>

using namespace std;

class TransRot{
	private:
		double x,y,z,newX,newY,newZ;
		string opType;
	
	public:
	
		TransRot(){
			setXYZ(0.0,0.0,0.0);
			newX = 0.0;
			newY = 0.0;
			newZ = 0.0;
		}
		
		double getRadianFromDegree(double value){
   			return value * M_PI / 180.0;
		}
		string getOperationType (void){
			return opType;
		}
		
		void updateCoordinates (void){
			x = newX;
			y = newY;
			z = newZ;
		}
		
		void printResult (void){
			cout<<"P("<<getX()<<","<<getY()<<","<<getZ()<<")"<<""<<"=======>"<<getOperationType()<<"=======>"<<"PNew("<<newX<<","<<newY<<","<<newZ<<")"<<endl;
		}			
		
		// GET AND SET METHODS
		
		void setXYZ(double x, double y, double z){
			setX(x);
			setY(y);
			setZ(z);	
		}
		void setX(double x){
			this->x = x;
		}
		void setY(double y){
			this->y = y;
		}
		void setZ(double z){
			this->z = z;
		}
		double getX(void){
			return x;
		}
		double getY(void){
			return y;
		}
		double getZ(void){
			return z;
		}
		
		// TRANSLATE OPERATIONS
		
		void translateAlongX (double value){
			newX = x + value;
			newY = y;
			newZ = z;
			opType = "TRANSLATE X";
		}
		void translateAlongY (double value){
			newY = y + value;
			newX = x;
			newZ = z;
			opType = "TRANSLATE Y";
		}
		void translateAlongZ (double value){
			newZ = z + value;
			newX = x;
			newY = y;
			opType = "TRANSLATE Z";
		}
		
		//ROTATE OPERATIONS
		
		void rotateAroundX (double value){
			double radian = getRadianFromDegree(value);
			newX = x;
			newY = y*cos(radian) - z*sin(radian);
			newZ = y*sin(radian) + z*cos(radian);
			opType = "ROTATE X";			
		}
		
		void rotateAroundY (double value){
			double radian = getRadianFromDegree(value);
			newX = x*cos(radian) + z*sin(radian);
			newY = y;
			newZ = -x*sin(radian) + z*cos(radian);
			opType = "ROTATE Y";			
		}
		
		void rotateAroundZ (double value){
			double radian = getRadianFromDegree(value);
			newX = x*cos(radian) - y*sin(radian);
			newY = x*sin(radian) + y*cos(radian);
			newZ = z;
			opType = "ROTATE Z";			
		}		
};

