#include <stdio.h>
#include <GL/gl.h>
#include <GL/glut.h>
#include<math.h>
float shift = 0;
double s=.07;
int i;
bool isDay = false;
void circle(double x, double y)
{


    glBegin(GL_TRIANGLE_FAN);
        for(i=0;i<360;i++)
        {
            x=x+cos((i*3.14)/180)*s;
            y=y+sin((i*3.14)/180)*s;

            glVertex2d(x,y);

        }


    glEnd();

}

void drawCircle(float cx, float cy, float r, int num_segments)
{
    float theta = 3.1415926 * 2 / float(num_segments);
    float tangetial_factor = tanf(theta);//calculate the tangential factor

    float radial_factor = cosf(theta);//calculate the radial factor

    float x = r;//we start at angle = 0

    float y = 0;
    glLineWidth(2);
    glBegin(GL_LINE_LOOP);
    for (int ii = 0; ii < num_segments; ii++)
    {
        glVertex2f(x + cx, y + cy);//output vertex

        //calculate the tangential vector
        //remember, the radial vector is (x, y)
        //to get the tangential vector we flip those coordinates and negate one of them

        float tx = -y;
        float ty = x;

        //add the tangential vector

        x += tx * tangetial_factor;
        y += ty * tangetial_factor;

        //correct using the radial factor

        x *= radial_factor;
        y *= radial_factor;
    }
    glEnd();


}

/* function to make the user able to deal with the system */
void key(int key, int x, int y) {
	switch (key)
	{
	case GLUT_KEY_DOWN:
		shift--;
		glutPostRedisplay();
		break;
	case GLUT_KEY_UP:
		shift++;
		glutPostRedisplay();
		break;

	}

}

float xpos=-1;
void idle(){
    if(xpos<=100.0){
        xpos+=0.005;
    }else{
        xpos=xpos-190.0;
    }
    glutPostRedisplay();
}




void display(void)
{
/* clear all pixels */
glClear (GL_COLOR_BUFFER_BIT);
/* draw white polygon (rectangle) with corners at
* (0.25, 0.25, 0.0) and (0.75, 0.75, 0.0)
*/
   glColor3f (0.0, 0.7, 0.2);


	glBegin(GL_QUADS);

	//Field
	glVertex3f(0.0f, 0.0f, 0.0f);
	glVertex3f(0.0f, 30.0f, 0.0f);
	glVertex3f(100.0f, 30.0f, 0.0f);
	glVertex3f(100.0f, 0.0f, 0.0f);

	glEnd();

	//Field

	//Square field

	glColor3f (1.0, 1.0, 1.0);

	glBegin(GL_LINES);

	glVertex3f(5.0f, 3.0f, 0.0f);
	glVertex3f(5.0f, 28.0f, 0.0f);

	glEnd();

	glBegin(GL_LINES);


	glVertex3f(5.0f, 28.0f, 0.0f);
	glVertex3f(75.0f, 28.0f, 0.0f);

	glEnd();

	glBegin(GL_LINES);


	glVertex3f(75.0f, 28.0f, 0.0f);
	glVertex3f(75.0f, 3.0f, 0.0f);

	glEnd();

	glBegin(GL_LINES);


	glVertex3f(75.0f, 3.0f, 0.0f);
	glVertex3f(5.0f, 3.0f, 0.0f);

	glEnd();

	//Square field end

    glBegin(GL_LINES);

    //Left Middle Square
	glVertex3f(5.0f, 19.5f, 0.0f);
	glVertex3f(8.0f, 19.5f, 0.0f);

	glVertex3f(5.0f, 11.5f, 0.0f);
	glVertex3f(8.0f, 11.5f, 0.0f);

	glVertex3f(8.0f, 19.5f, 0.0f);
    glVertex3f(8.0f, 11.5f, 0.0f);
    //Left Middle Square

    //Right Middle Square
    glVertex3f(75.0f, 19.5f, 0.0f);
	glVertex3f(72.0f, 19.5f, 0.0f);

	glVertex3f(75.0f, 11.5f, 0.0f);
	glVertex3f(72.0f, 11.5f, 0.0f);

	glVertex3f(72.0f, 19.5f, 0.0f);
    glVertex3f(72.0f, 11.5f, 0.0f);
    //Right Middle Square


    //Left big middle Square
    glVertex3f(5.0f, 24.0f, 0.0f);
    glVertex3f(15.0f, 24.0f, 0.0f);

    glVertex3f(5.0f, 7.0f, 0.0f);
    glVertex3f(15.0f, 7.0f, 0.0f);

    glVertex3f(15.0f, 24.0f, 0.0f);
    glVertex3f(15.0f, 7.0f, 0.0f);
    //Left big middle Square

    //Right big middle Square
    glVertex3f(75.0f, 24.0f, 0.0f);
    glVertex3f(65.0f, 24.0f, 0.0f);

    glVertex3f(75.0f, 7.0f, 0.0f);
    glVertex3f(65.0f, 7.0f, 0.0f);

    glVertex3f(65.0f, 24.0f, 0.0f);
    glVertex3f(65.0f, 7.0f, 0.0f);
    //Right big middle Square


    glVertex3f(40.0f, 28.0f, 0.0f);
    glVertex3f(40.0f, 3.0f, 0.0f);

	glEnd();


    //sky and sun and moon
    if (isDay) {
        glColor3f(0.0f, 0.0f, 0.0f);
        glBegin(GL_QUADS);

        glVertex3f(0.0f, 30.0f, 0.0f);
        glVertex3f(0.0f, 100.0f, 0.0f);
        glVertex3f(100.0f, 100.0f, 0.0f);
        glVertex3f(100.00f, 30.0f, 0.0f);

        glEnd();

        //Moon
        glColor3f (0.902, 0.902, 0.980 );
        circle(10.0,78.0+shift);
        //Moon

    }
    else {
        glColor3f (0.000, 0.808, 0.820);
        glBegin(GL_QUADS);

        glVertex3f(0.0f, 30.0f, 0.0f);
        glVertex3f(0.0f, 100.0f, 0.0f);
        glVertex3f(100.0f, 100.0f, 0.0f);
        glVertex3f(100.00f, 30.0f, 0.0f);

        glEnd();

        //Sun
        glColor3f (1.000, 0.700, 0.0);
        circle(75.0,78.0+shift);
        //Sun
    }
	//sky





    //Middle Circle
    glColor3f(1.0, 1.0, 1.0);
    drawCircle(40.0, 15.0, 5, 360);
    //Middle Circle

    //Left Circle
    glColor3f(1.0, 1.0, 1.0);
    drawCircle(15.0, 15.0, 3, 360);
    glColor3f (0.0, 0.7, 0.2);
    glBegin(GL_POLYGON);
    glVertex3f(10.0f, 24.0f, 0.0f);
    glVertex3f(14.9f, 24.0f, 0.0f);
    glVertex3f(14.9f, 10.0f, 0.0f);
    glVertex3f(10.0f, 10.0f, 0.0f);
    glEnd();
    //Left Circle

    //Right Circle
    glColor3f(1.0, 1.0, 1.0);
    drawCircle(65.0, 15.0, 3, 360);
    glColor3f (0.0, 0.7, 0.2);
    glBegin(GL_POLYGON);
    glVertex3f(70.0f, 24.0f, 0.0f);
    glVertex3f(65.0f, 24.0f, 0.0f);
    glVertex3f(65.0f, 10.0f, 0.0f);
    glVertex3f(70.0f, 10.0f, 0.0f);
    glEnd();
    //Right Circle

    //Road

    glBegin(GL_POLYGON);
    glColor3f(1.000, 0.871, 0.678);
    glVertex3f(0.0f, 0.0f, 0.0f);
    glVertex3f(5.0f, 30.0f, 0.0f);
    glVertex3f(3.0f, 30.0f, 0.0f);
    glVertex3f(0.0f, 11.0f, 0.0f);

    glEnd();

    glBegin(GL_POLYGON);
    glVertex3f(0.0f, 30.0f, 0.0f);
    glVertex3f(100.0f, 30.0f, 0.0f);
    glVertex3f(100.0f, 34.0f, 0.0f);
    glVertex3f(0.0f, 34.0f, 0.0f);
    glEnd();

    glColor3f(0.3, 0.3, 0.3);
    glBegin(GL_LINES);
    glVertex3f(100.0f, 34.0f, 0.0f);
    glVertex3f(0.0f, 34.0f, 0.0f);

    glVertex3f(5.0f, 30.0f, 0.0f);
    glVertex3f(100.0f, 30.0f, 0.0f);

    glVertex3f(5.0f, 30.0f, 0.0f);
    glVertex3f(0.0f, 0.0f, 0.0f);

    glVertex3f(3.0f, 30.0f, 0.0f);
    glVertex3f(0.0f, 11.0f, 0.0f);

    glVertex3f(3.0f, 30.0f, 0.0f);
    glVertex3f(0.0f, 30.0f, 0.0f);

    glEnd();

    //wall-mosjid

    glColor3f(0.722, 0.525, 0.043);
    glBegin(GL_POLYGON);
    glVertex3f(42.5f, 34.0f, 0.0f);
    glVertex3f(42.5f, 37.0f, 0.0f);
    glVertex3f(62.5f, 37.0f, 0.0f);
    glVertex3f(62.5f, 34.0f, 0.0f);
    glEnd();

    glColor3f(0.502, 0.502, 0.502);
    glBegin(GL_POLYGON);
    glVertex3f(42.5f, 34.0f, 0.0f);
    glVertex3f(42.5f, 37.5f, 0.0f);
    glVertex3f(43.f, 37.5f, 0.0f);
    glVertex3f(43.f, 34.0f, 0.0f);
    glEnd();





    //Road


    //Mosjid
    glColor3f(0.467, 0.533, 0.600);
    glBegin(GL_QUADS);
    glVertex3f(65.0f, 34.0f, 0.0f);
    glVertex3f(55.0f, 34.0f, 0.0f);
    glVertex3f(52.0f, 45.0f, 0.0f);
    glVertex3f(68.0f, 45.0f, 0.0f);
    glEnd();

    glColor3f(0.827, 0.827, 0.827);
    glBegin(GL_QUADS);
    glVertex3f(69.0f, 45.0f, 0.0f);
    glVertex3f(51.0f, 45.0f, 0.0f);
    glVertex3f(51.0f, 47.0f, 0.0f);
    glVertex3f(69.0f, 47.0f, 0.0f);
    glEnd();

    glColor3f(0.184, 0.310, 0.310);
    glBegin(GL_LINES);
    glVertex3f(69.0f, 45.0f, 0.0f);
    glVertex3f(51.0f, 45.0f, 0.0f);

    glVertex3f(51.0f, 47.0f, 0.0f);
    glVertex3f(69.0f, 47.0f, 0.0f);

    glVertex3f(51.0f, 45.0f, 0.0f);
    glVertex3f(51.0f, 47.0f, 0.0f);

    glVertex3f(69.0f, 45.0f, 0.0f);
    glVertex3f(69.0f, 47.0f, 0.0f);
    glEnd();

    glColor3f(0.000, 0.000, 0.000);
    glBegin(GL_QUADS);
    glVertex3f(65.0f, 44.0f, 0.0f);
    glVertex3f(55.0f, 44.0f, 0.0f);
    glVertex3f(55.0f, 42.5f, 0.0f);
    glVertex3f(65.0f, 42.5f, 0.0f);
    glEnd();

    glColor3f(0.545, 0.271, 0.075);
    glBegin(GL_QUADS);
    glVertex3f(64.0f, 41.5f, 0.0f);
    glVertex3f(56.0f, 41.5f, 0.0f);
    glVertex3f(56.0f, 39.5f, 0.0f);
    glVertex3f(64.0f, 39.5f, 0.0f);
    glEnd();

    glColor3f(0.545, 0.271, 0.075);
    glBegin(GL_QUADS);
    glVertex3f(56.0f, 39.5f, 0.0f);
    glVertex3f(57.0f, 39.5f, 0.0f);
    glVertex3f(57.0f, 34.0f, 0.0f);
    glVertex3f(56.0f, 34.0f, 0.0f);
    glEnd();

    glColor3f(0.545, 0.271, 0.075);
    glBegin(GL_QUADS);
    glVertex3f(64.0f, 39.5f, 0.0f);
    glVertex3f(63.0f, 39.5f, 0.0f);
    glVertex3f(63.0f, 34.0f, 0.0f);
    glVertex3f(64.0f, 34.0f, 0.0f);
    glEnd();

    glColor3f(1.0, 1.0, 1.0);
    glBegin(GL_QUADS);
    glVertex3f(57.0f, 39.5f, 0.0f);
    glVertex3f(63.0f, 39.5f, 0.0f);
    glVertex3f(63.0f, 34.0f, 0.0f);
    glVertex3f(57.0f, 34.0f, 0.0f);
    glEnd();

    glColor3f(0.118, 0.565, 1.000);
    glBegin(GL_QUADS);
    glVertex3f(59.0f, 34.0f, 0.0f);
    glVertex3f(61.0f, 34.0f, 0.0f);
    glVertex3f(61.0f, 37.0f, 0.0f);
    glVertex3f(59.0f, 37.0f, 0.0f);
    glEnd();

    glBegin(GL_TRIANGLES);
    glVertex3f(59.0f, 37.0f, 0.0f);
    glVertex3f(61.0f, 37.0f, 0.0f);
    glVertex3f(60.0f, 38.5f, 0.0f);
    glEnd();

    glColor3f(0.804, 0.361, 0.361);
    glBegin(GL_QUADS);
    glVertex3f(67.0f, 34.0f, 0.0f);
    glVertex3f(53.0f, 34.0f, 0.0f);
    glVertex3f(53.0f, 35.0f, 0.0f);
    glVertex3f(67.0f, 35.0f, 0.0f);
    glEnd();
    //Mosjid

    //Tree Right
    glColor3f(0.545, 0.000, 0.000);
    glBegin(GL_QUADS);
    glVertex3f(80.0f, 34.1f, 0.0f);
    glVertex3f(81.5f, 34.1f, 0.0f);
    glVertex3f(81.5f, 40.0f, 0.0f);
    glVertex3f(80.0f, 40.0f, 0.0f);
    glEnd();

    glColor3f(0.0, 0.7, 0.2);
    glBegin(GL_TRIANGLES);
    glVertex3f(77.0f, 40.0f, 0.0f);
    glVertex3f(84.5f, 40.0f, 0.0f);
    glVertex3f(80.85f, 45.0f, 0.0f);
    glEnd();

    glColor3f(0.0, 0.7, 0.2);
    glBegin(GL_TRIANGLES);
    glVertex3f(77.0f, 42.0f, 0.0f);
    glVertex3f(84.5f, 42.0f, 0.0f);
    glVertex3f(80.85f, 47.0f, 0.0f);
    glEnd();

    glColor3f(0.0, 0.7, 0.2);
    glBegin(GL_TRIANGLES);
    glVertex3f(77.0f, 44.0f, 0.0f);
    glVertex3f(84.5f, 44.0f, 0.0f);
    glVertex3f(80.85f, 49.0f, 0.0f);
    glEnd();

    glColor3f(0.545, 0.000, 0.000);
    glBegin(GL_QUADS);
    glVertex3f(87.0f, 34.1f, 0.0f);
    glVertex3f(88.5f, 34.1f, 0.0f);
    glVertex3f(88.5f, 40.0f, 0.0f);
    glVertex3f(87.0f, 40.0f, 0.0f);
    glEnd();

    glColor3f(0.0, 0.7, 0.2);
    glBegin(GL_TRIANGLES);
    glVertex3f(84.0f, 40.0f, 0.0f);
    glVertex3f(91.5f, 40.0f, 0.0f);
    glVertex3f(87.5f, 45.0f, 0.0f);
    glEnd();

    glColor3f(0.0, 0.7, 0.2);
    glBegin(GL_TRIANGLES);
    glVertex3f(84.0f, 42.0f, 0.0f);
    glVertex3f(91.5f, 42.0f, 0.0f);
    glVertex3f(87.5f, 47.0f, 0.0f);
    glEnd();

    glColor3f(0.0, 0.7, 0.2);
    glBegin(GL_TRIANGLES);
    glVertex3f(84.0f, 44.0f, 0.0f);
    glVertex3f(91.5f, 44.0f, 0.0f);
    glVertex3f(87.5f, 49.0f, 0.0f);
    glEnd();


    glColor3f(0.545, 0.000, 0.000);
    glBegin(GL_QUADS);
    glVertex3f(92.0f, 34.1f, 0.0f);
    glVertex3f(93.5f, 34.1f, 0.0f);
    glVertex3f(93.5f, 43.0f, 0.0f);
    glVertex3f(92.0f, 43.0f, 0.0f);
    glEnd();

    glColor3f(0.0, 0.7, 0.2);
    glBegin(GL_TRIANGLES);
    glVertex3f(89.0f, 43.0f, 0.0f);
    glVertex3f(96.5f, 43.0f, 0.0f);
    glVertex3f(92.75f, 48.0f, 0.0f);
    glEnd();

    glColor3f(0.0, 0.7, 0.2);
    glBegin(GL_TRIANGLES);
    glVertex3f(89.0f, 45.0f, 0.0f);
    glVertex3f(96.5f, 45.0f, 0.0f);
    glVertex3f(92.75f, 50.0f, 0.0f);
    glEnd();

    glColor3f(0.0, 0.7, 0.2);
    glBegin(GL_TRIANGLES);
    glVertex3f(89.0f, 47.0f, 0.0f);
    glVertex3f(96.5f, 47.0f, 0.0f);
    glVertex3f(92.75f, 52.0f, 0.0f);
    glEnd();

    glColor3f(0.545, 0.000, 0.000);
    glBegin(GL_QUADS);
    glVertex3f(98.0f, 34.1f, 0.0f);
    glVertex3f(99.5f, 34.1f, 0.0f);
    glVertex3f(99.5f, 43.0f, 0.0f);
    glVertex3f(98.0f, 43.0f, 0.0f);
    glEnd();

    glColor3f(0.0, 0.7, 0.2);
    glBegin(GL_TRIANGLES);
    glVertex3f(95.0f, 43.0f, 0.0f);
    glVertex3f(102.5f, 43.0f, 0.0f);
    glVertex3f(98.75f, 48.0f, 0.0f);
    glEnd();

    glColor3f(0.0, 0.7, 0.2);
    glBegin(GL_TRIANGLES);
    glVertex3f(95.0f, 45.0f, 0.0f);
    glVertex3f(102.5f, 45.0f, 0.0f);
    glVertex3f(98.75f, 50.0f, 0.0f);
    glEnd();

    glColor3f(0.0, 0.7, 0.2);
    glBegin(GL_TRIANGLES);
    glVertex3f(95.0f, 47.0f, 0.0f);
    glVertex3f(102.5f, 47.0f, 0.0f);
    glVertex3f(98.75f, 52.0f, 0.0f);
    glEnd();
    //Tree Right

    //AB1
    glColor3f(0.0, 0.7, 0.2);
    glBegin(GL_POLYGON);
    glVertex3f(4.0f, 34.0f, 0.0f);
    glVertex3f(4.0f, 46.0f, 0.0f);
    glVertex3f(15.0f, 46.0f, 0.0f);
    glVertex3f(15.0f, 34.0f, 0.0f);
    glEnd();
    //line
    glColor3f (0.0, 0.0, 0.0);

	glBegin(GL_LINES);

	glVertex3f(4.0f, 34.0f, 0.0f);
	glVertex3f(4.0f, 46.0f, 0.0f);

    glVertex3f(4.0f, 34.0f, 0.0f);
	glVertex3f(15.0f, 34.0f, 0.0f);

	glVertex3f(15.0f, 34.0f, 0.0f);
	glVertex3f(15.0f, 46.0f, 0.0f);
	glEnd();


    glColor3f(1.0, 0.7, 0.2);

    glBegin(GL_POLYGON);
    glVertex3f(3.0f, 46.0f, 0.0f);
    glVertex3f(3.0f, 50.0f, 0.0f);
    glVertex3f(16.0f, 50.0f, 0.0f);
    glVertex3f(16.0f, 46.0f, 0.0f);

    glEnd();
    //chal-line
    glColor3f (0.0, 0.0, 0.0);

	glBegin(GL_LINES);

	glVertex3f(3.0f, 46.0f, 0.0f);
	glVertex3f(16.0f, 46.0f, 0.0f);

	glVertex3f(3.0f, 46.0f, 0.0f);
	glVertex3f(3.0f, 50.0f, 0.0f);

	glVertex3f(16.0f, 46.0f, 0.0f);
	glVertex3f(16.0f, 50.0f, 0.0f);

	glVertex3f(3.0f, 50.0f, 0.0f);
	glVertex3f(16.0f, 50.0f, 0.0f);
    glEnd();
    glColor3f(1.0, 0.0, 0.0);
    glBegin(GL_POLYGON);
    glVertex3f(4.0f, 34.0f, 0.0f);
    glVertex3f(4.0f, 40.0f, 0.0f);
    glVertex3f(15.0f, 40.0f, 0.0f);
    glVertex3f(15.0f, 34.0f, 0.0f);
    glEnd();
    glColor3f(0.502, 0.502, 0.502);
    glBegin(GL_POLYGON);
    glVertex3f(4.0f, 40.0f, 0.0f);
    glVertex3f(4.0f, 46.0f, 0.0f);
    glVertex3f(15.0f, 46.0f, 0.0f);
    glVertex3f(15.0f, 40.0f, 0.0f);

    glEnd();

    //door
    glColor3f(0.118, 0.565, 1.000);
    glBegin(GL_POLYGON);
    glVertex3f(5.0f, 34.0f, 0.0f);
    glVertex3f(5.0f, 42.0f, 0.0f);
    glVertex3f(8.0f, 42.0f, 0.0f);
    glVertex3f(8.0f, 34.0f, 0.0f);
    glEnd();
    //line
    glColor3f (0.0, 0.0, 0.0);

	glBegin(GL_LINES);

	glVertex3f(5.0f, 34.0f, 0.0f);
	glVertex3f(5.0f, 42.0f, 0.0f);

	glVertex3f(5.0f, 42.0f, 0.0f);
	glVertex3f(8.0f, 42.0f, 0.0f);

	glVertex3f(8.0f, 42.0f, 0.0f);
	glVertex3f(8.0f, 34.0f, 0.0f);

	glVertex3f(6.5f, 42.0f, 0.0f);
	glVertex3f(6.5f, 34.0f, 0.0f);

	  glEnd();
	  //door2
    glColor3f(0.118, 0.565, 1.000);
    glBegin(GL_POLYGON);
    glVertex3f(14.0f, 34.0f, 0.0f);
    glVertex3f(14.0f, 42.0f, 0.0f);
    glVertex3f(11.0f, 42.0f, 0.0f);
    glVertex3f(11.0f, 34.0f, 0.0f);
    glEnd();
    //doorline2
    glColor3f (0.0, 0.0, 0.0);

	glBegin(GL_LINES);

	glVertex3f(14.0f, 34.0f, 0.0f);
	glVertex3f(14.0f, 42.0f, 0.0f);

	glVertex3f(14.0f, 42.0f, 0.0f);
	glVertex3f(11.0f, 42.0f, 0.0f);

	glVertex3f(11.0f, 42.0f, 0.0f);
	glVertex3f(11.0f, 34.0f, 0.0f);

	glVertex3f(12.5f, 42.0f, 0.0f);
	glVertex3f(12.5f, 34.0f, 0.0f);

	  glEnd();
	  //AB1

     glColor3f(1.0, 1.0, 1.0);
     glBegin(GL_POLYGON);
    glVertex3f(18.5f, 34.0f, 0.0f);
    glVertex3f(18.5f, 58.0f, 0.0f);
    glVertex3f(25.5f, 58.0f, 0.0f);
    glVertex3f(25.5f, 34.0f, 0.0f);
     glEnd();
     glColor3f (0.0, 0.0, 0.0);

	glBegin(GL_LINES);

	glVertex3f(18.5f, 34.f, 0.0f);
	glVertex3f(18.5f, 58.f, 0.0f);

	glVertex3f(18.5f, 58.f, 0.0f);
	glVertex3f(25.55f, 58.f, 0.0f);


	glVertex3f(25.55f, 34.f, 0.0f);
	glVertex3f(25.55f, 58.f, 0.0f);




glEnd();

    glColor3f(0.245, 0.000, 0.00);
    glBegin(GL_POLYGON);
    glVertex3f(19.0f, 34.0f, 0.0f);
    glVertex3f(19.0f, 57.5f, 0.0f);
    glVertex3f(24.5f, 57.5f, 0.0f);
    glVertex3f(24.5f, 34.0f, 0.0f);
    glEnd();

  //ab1-windo
    glColor3f(1.0, 1.000, 1.000);
    glBegin(GL_POLYGON);
    glVertex3f(21.f, 53.5f, 0.0f);
    glVertex3f(21.f, 55.5f, 0.0f);
    glVertex3f(23.5f, 55.5f, 0.0f);
    glVertex3f(23.5f, 53.5f, 0.0f);

    glEnd();
     glColor3f (0.0, 0.0, 0.0);

	glBegin(GL_LINES);

	glVertex3f(21.5f, 53.5f, 0.0f);
	glVertex3f(21.5f, 55.55f, 0.0f);

	glVertex3f(22.f, 53.5f, 0.0f);
	glVertex3f(22.f, 55.55f, 0.0f);


	glVertex3f(22.5f, 53.5f, 0.0f);
	glVertex3f(22.5f, 55.55f, 0.0f);

	glVertex3f(23.f, 53.5f, 0.0f);
	glVertex3f(23.f, 55.5f, 0.0f);




	    glEnd();



    glColor3f(1.0, 1.000, 1.000);
    glBegin(GL_POLYGON);
    glVertex3f(21.f, 50.5f, 0.0f);
    glVertex3f(21.f, 52.5f, 0.0f);
    glVertex3f(23.5f, 52.5f, 0.0f);
    glVertex3f(23.5f, 50.5f, 0.0f);

    glEnd();

     glColor3f (0.0, 0.0, 0.0);

	glBegin(GL_LINES);

	glVertex3f(21.5f, 50.5f, 0.0f);
	glVertex3f(21.5f, 52.55f, 0.0f);

	glVertex3f(22.f, 50.5f, 0.0f);
	glVertex3f(22.f, 52.55f, 0.0f);


	glVertex3f(22.5f, 50.5f, 0.0f);
	glVertex3f(22.5f, 52.55f, 0.0f);

	glVertex3f(23.f, 50.5f, 0.0f);
	glVertex3f(23.f, 52.55f, 0.0f);




	    glEnd();

    glColor3f(1.0, 1.000, 1.000);
    glBegin(GL_POLYGON);
    glVertex3f(21.f, 47.5f, 0.0f);
    glVertex3f(21.f, 49.5f, 0.0f);
    glVertex3f(23.5f, 49.5f, 0.0f);
    glVertex3f(23.5f, 47.5f, 0.0f);

    glEnd();

     glColor3f (0.0, 0.0, 0.0);

	glBegin(GL_LINES);

	glVertex3f(21.5f, 47.5f, 0.0f);
	glVertex3f(21.5f, 49.55f, 0.0f);

	glVertex3f(22.f, 47.5f, 0.0f);
	glVertex3f(22.f, 49.55f, 0.0f);


	glVertex3f(22.5f, 47.5f, 0.0f);
	glVertex3f(22.5f, 49.55f, 0.0f);

	glVertex3f(23.f, 47.5f, 0.0f);
	glVertex3f(23.f, 49.55f, 0.0f);




	    glEnd();

    glColor3f(1.0, 1.000, 1.000);
    glBegin(GL_POLYGON);
    glVertex3f(21.f, 44.5f, 0.0f);
    glVertex3f(21.f, 46.5f, 0.0f);
    glVertex3f(23.5f, 46.5f, 0.0f);
    glVertex3f(23.5f, 44.5f, 0.0f);

    glEnd();

    glColor3f (0.0, 0.0, 0.0);

	glBegin(GL_LINES);

	glVertex3f(21.5f, 44.5f, 0.0f);
	glVertex3f(21.5f, 46.55f, 0.0f);

	glVertex3f(22.f, 44.5f, 0.0f);
	glVertex3f(22.f, 46.55f, 0.0f);


	glVertex3f(22.5f, 44.5f, 0.0f);
	glVertex3f(22.5f, 46.55f, 0.0f);

	glVertex3f(23.f, 44.5f, 0.0f);
	glVertex3f(23.f, 46.55f, 0.0f);


glEnd();



    glColor3f(1.0, 1.000, 1.000);
    glBegin(GL_POLYGON);
    glVertex3f(21.f, 41.5f, 0.0f);
    glVertex3f(21.f, 43.5f, 0.0f);
    glVertex3f(23.5f, 43.5f, 0.0f);
    glVertex3f(23.5f, 41.5f, 0.0f);

    glEnd();
    glColor3f (0.0, 0.0, 0.0);

	glBegin(GL_LINES);

	glVertex3f(21.5f, 41.5f, 0.0f);
	glVertex3f(21.5f, 43.55f, 0.0f);

	glVertex3f(22.f, 41.5f, 0.0f);
	glVertex3f(22.f, 43.55f, 0.0f);


	glVertex3f(22.5f, 41.5f, 0.0f);
	glVertex3f(22.5f, 43.55f, 0.0f);

	glVertex3f(23.f, 41.5f, 0.0f);
	glVertex3f(23.f, 43.55f, 0.0f);


    glEnd();


  //ab1-secondpart
   glColor3f(1.0, 1.000, 1.000);
    glBegin(GL_POLYGON);
    glVertex3f(25.5f, 34.f, 0.0f);
    glVertex3f(25.5f, 58.f, 0.0f);
    glVertex3f(33.f, 57.5f, 0.0f);
    glVertex3f(33.f, 34.f,0.0f);

    glEnd();
    glColor3f (0.0, 0.0, 0.0);

	glBegin(GL_LINES);

    glVertex3f(25.55f, 34.f, 0.0f);
	glVertex3f(25.55f, 58.f, 0.0f);

   glEnd();


    glColor3f(0.245, 0.000, 0.00);
    glBegin(GL_POLYGON);
    glVertex3f(26.5f, 34.f, 0.0f);
    glVertex3f(26.5f, 56.5f, 0.0f);
    glVertex3f(33.f, 56.f, 0.0f);
    glVertex3f(33.f, 34.f,0.0f);

    glEnd();

    glColor3f (0.0, 0.0, 0.0);

	glBegin(GL_LINES);

    glVertex3f(25.5f, 58.f, 0.0f);
	glVertex3f(33.f, 57.5f, 0.0f);

   glEnd();

    glColor3f(1.0, 1.000, 1.00);
    glBegin(GL_POLYGON);
    glVertex3f(26.5f, 34.f, 0.0f);
    glVertex3f(26.5f, 54.5f, 0.0f);
    glVertex3f(31.f, 54.f, 0.0f);
    glVertex3f(32.f, 53.f, 0.0f);
    glVertex3f(32.f, 34.f,0.0f);

    glEnd();

    glColor3f(.700, 0.000, 0.000);
    glBegin(GL_POLYGON);
    glVertex3f(26.5f, 51.f, 0.0f);
    glVertex3f(26.5f, 53.5f, 0.0f);
    glVertex3f(30.f, 53.5f, 0.0f);
    glVertex3f(30.f, 51.f,0.0f);
    glEnd();

    glColor3f(.700, 0.000, 0.000);
    glBegin(GL_POLYGON);
    glVertex3f(26.5f, 48.f, 0.0f);
    glVertex3f(26.5f, 50.5f, 0.0f);
    glVertex3f(30.f,  50.5f, 0.0f);
    glVertex3f(30.f,  48.f,0.0f);
    glEnd();


    glColor3f(.700, 0.000, 0.000);
    glBegin(GL_POLYGON);
    glVertex3f(26.5f, 45.f, 0.0f);
    glVertex3f(26.5f, 47.5f, 0.0f);
    glVertex3f(30.f, 47.5f, 0.0f);
    glVertex3f(30.f, 45.f,0.0f);
    glEnd();

    glColor3f(.700, 0.000, 0.000);
    glBegin(GL_POLYGON);
    glVertex3f(26.5f, 42.f, 0.0f);
    glVertex3f(26.5f, 44.5f, 0.0f);
    glVertex3f(30.f, 44.5f, 0.0f);
    glVertex3f(30.f, 42.f,0.0f);
    glEnd();

    glColor3f(.700, 0.000, 0.000);
    glBegin(GL_POLYGON);
    glVertex3f(26.5f, 39.f, 0.0f);
    glVertex3f(26.5f, 41.5f, 0.0f);
    glVertex3f(30.f, 41.5f, 0.0f);
    glVertex3f(30.f, 39.f,0.0f);



    glEnd();

    glColor3f(0.118, 0.565, 1.000);
    glBegin(GL_POLYGON);
    glVertex3f(30.75f, 51.f, 0.0f);
    glVertex3f(30.75f, 53.5f, 0.0f);
    glVertex3f(31.75f, 53.f, 0.0f);
    glVertex3f(31.75f, 51.f,0.0f);



    glEnd();

    glColor3f(0.118, 0.565, 1.000);
    glBegin(GL_POLYGON);
    glVertex3f(30.75f, 48.f, 0.0f);
    glVertex3f(30.75f, 50.5f, 0.0f);
    glVertex3f(31.75f, 50.5f, 0.0f);
    glVertex3f(31.75f, 48.f,0.0f);



    glEnd();

    glColor3f(0.118, 0.565, 1.000);
    glBegin(GL_POLYGON);
    glVertex3f(30.75f, 45.f, 0.0f);
    glVertex3f(30.75f, 47.5f, 0.0f);
    glVertex3f(31.75f, 47.5f, 0.0f);
    glVertex3f(31.75f, 45.f,0.0f);



    glEnd();

    glColor3f(0.118, 0.565, 1.000);
    glBegin(GL_POLYGON);
    glVertex3f(30.75f, 42.f, 0.0f);
    glVertex3f(30.75f, 44.5f, 0.0f);
    glVertex3f(31.75f, 44.5f, 0.0f);
    glVertex3f(31.75f, 42.f,0.0f);



    glEnd();
    glColor3f(0.118, 0.565, 1.000);
    glBegin(GL_POLYGON);
    glVertex3f(30.75f, 39.f, 0.0f);
    glVertex3f(30.75f, 41.5f, 0.0f);
    glVertex3f(31.75f, 41.5f, 0.0f);
    glVertex3f(31.75f, 39.f,0.0f);



    glEnd();
        //ab1 3rd part
    glColor3f(1.0, 1.0, 1.000);
    glBegin(GL_POLYGON);
    glVertex3f(33.f, 37.f, 0.0f);
    glVertex3f(33.f, 57.5f, 0.0f);
    glVertex3f(42.f, 55.5f, 0.0f);
    glVertex3f(42.f, 37.f,0.0f);
   glEnd();

   glColor3f (0.0, 0.0, 0.0);

	glBegin(GL_LINES);

    glVertex3f(33.f, 57.5f, 0.0f);
	glVertex3f(42.f, 55.5f, 0.0f);

   glEnd();


    glColor3f(.700, 0.000, 0.000);
    glBegin(GL_POLYGON);
    glVertex3f(33.5f, 52.5f, 0.0f);
    glVertex3f(33.5f, 55.f, 0.0f);
    glVertex3f(37.f,  55.f, 0.0f);
    glVertex3f(37.f,  52.5f,0.0f);
    glEnd();

     glColor3f(.700, 0.000, 0.000);
    glBegin(GL_POLYGON);
    glVertex3f(33.5f, 49.5f, 0.0f);
    glVertex3f(33.5f, 52.f, 0.0f);
    glVertex3f(37.f,  52.f, 0.0f);
    glVertex3f(37.f,  49.5f,0.0f);
    glEnd();

   glColor3f(.700, 0.000, 0.000);
    glBegin(GL_POLYGON);
    glVertex3f(33.5f, 46.5f, 0.0f);
    glVertex3f(33.5f, 49.f, 0.0f);
    glVertex3f(37.f,  49.f, 0.0f);
    glVertex3f(37.f,  46.5f,0.0f);
    glEnd();

    glColor3f(.700, 0.000, 0.000);
    glBegin(GL_POLYGON);
    glVertex3f(33.5f, 43.5f, 0.0f);
    glVertex3f(33.5f, 46.f, 0.0f);
    glVertex3f(37.f,  46.f, 0.0f);
    glVertex3f(37.f,  43.5f,0.0f);
    glEnd();

    glColor3f(.700, 0.000, 0.000);
    glBegin(GL_POLYGON);
    glVertex3f(33.5f, 40.5f, 0.0f);
    glVertex3f(33.5f, 43.f, 0.0f);
    glVertex3f(37.f,  43.f, 0.0f);
    glVertex3f(37.f,  40.5f,0.0f);
    glEnd();

    glColor3f(.700, 0.000, 0.000);
    glBegin(GL_POLYGON);
    glVertex3f(33.5f, 37.5f, 0.0f);
    glVertex3f(33.5f, 40.f, 0.0f);
    glVertex3f(37.f,  40.f, 0.0f);
    glVertex3f(37.f,  37.5f,0.0f);
    glEnd();









    glColor3f(.700, 0.000, 0.000);
    glBegin(GL_POLYGON);
    glVertex3f(37.5f, 52.5f, 0.0f);
    glVertex3f(37.5f, 55.f, 0.0f);
    glVertex3f(41.f,  55.f, 0.0f);
    glVertex3f(41.f,  52.5f,0.0f);
    glEnd();

     glColor3f(.700, 0.000, 0.000);
    glBegin(GL_POLYGON);
    glVertex3f(37.5f, 49.5f, 0.0f);
    glVertex3f(37.5f, 52.f, 0.0f);
    glVertex3f(41.f,  52.f, 0.0f);
    glVertex3f(41.f,  49.5f,0.0f);
    glEnd();

   glColor3f(.700, 0.000, 0.000);
    glBegin(GL_POLYGON);
    glVertex3f(37.5f, 46.5f, 0.0f);
    glVertex3f(37.5f, 49.f, 0.0f);
    glVertex3f(41.f,  49.f, 0.0f);
    glVertex3f(41.f,  46.5f,0.0f);
    glEnd();

    glColor3f(.700, 0.000, 0.000);
    glBegin(GL_POLYGON);
    glVertex3f(37.5f, 43.5f, 0.0f);
    glVertex3f(37.5f, 46.f, 0.0f);
    glVertex3f(41.f,  46.f, 0.0f);
    glVertex3f(41.f,  43.5f,0.0f);
    glEnd();

    glColor3f(.700, 0.000, 0.000);
    glBegin(GL_POLYGON);
    glVertex3f(37.5f, 40.5f, 0.0f);
    glVertex3f(37.5f, 43.f, 0.0f);
    glVertex3f(41.f,  43.f, 0.0f);
    glVertex3f(41.f,  40.5f,0.0f);
    glEnd();

    glColor3f(.700, 0.000, 0.000);
    glBegin(GL_POLYGON);
    glVertex3f(37.5f, 37.5f, 0.0f);
    glVertex3f(37.5f, 40.f, 0.0f);
    glVertex3f(41.f,  40.f, 0.0f);
    glVertex3f(41.f,  37.5f,0.0f);
    glEnd();
    //ab1 part4


    glColor3f(1.0, 1.0, 1.000);
    glBegin(GL_POLYGON);
    glVertex3f(42.f, 37.f, 0.0f);
    glVertex3f(42.f, 55.5f, 0.0f);
    glVertex3f(46.f, 55.f, 0.0f);
    glVertex3f(46.f, 37.f,0.0f);

    glEnd();

    glColor3f(1.0, 1.0, 1.000);
    glBegin(GL_POLYGON);
    glVertex3f(42.f, 48.f, 0.0f);
    glVertex3f(42.f, 51.5f, 0.0f);
    glVertex3f(48.f, 51.5f, 0.0f);
    glVertex3f(48.f, 48.f,0.0f);

    glEnd();

    glColor3f(1.0, 1.0, 1.000);
    glBegin(GL_POLYGON);
    glVertex3f(42.f, 37.f, 0.0f);
    glVertex3f(42.f, 48.f, 0.0f);
    glVertex3f(50.f, 48.f, 0.0f);
    glVertex3f(50.f, 37.f,0.0f);

    glEnd();

    glColor3f(.700, 0.000, 0.000);
    glBegin(GL_POLYGON);
    glVertex3f(42.f, 48.f, 0.0f);
    glVertex3f(42.f, 51.5f, 0.0f);
    glVertex3f(47.5f, 51.5f, 0.0f);
    glVertex3f(47.5f, 48.f,0.0f);

    glEnd();

    glColor3f(.700, 0.000, 0.000);
    glBegin(GL_POLYGON);
    glVertex3f(42.f, 44.f, 0.0f);
    glVertex3f(42.f, 47.5f, 0.0f);
    glVertex3f(49.5f, 47.5f, 0.0f);
    glVertex3f(49.5f, 44.f,0.0f);

    glEnd();

   glColor3f(.700, 0.000, 0.000);
    glBegin(GL_POLYGON);
    glVertex3f(42.f, 40.f, 0.0f);
    glVertex3f(42.f, 43.5f, 0.0f);
    glVertex3f(49.5f, 43.5f, 0.0f);
    glVertex3f(49.5f, 40.f,0.0f);

   glEnd();


   glColor3f(.700, 0.000, 0.000);
    glBegin(GL_POLYGON);
    glVertex3f(42.f, 37.f, 0.0f);
    glVertex3f(42.f, 39.5f, 0.0f);
    glVertex3f(49.5f, 39.5f, 0.0f);
    glVertex3f(49.5f, 37.f,0.0f);

   glEnd();
   glColor3f(.000, 0.0, 0.000);

   glBegin(GL_LINES);

    glVertex3f(42.f, 55.5f, 0.0f);
	glVertex3f(46.f, 55.f, 0.0f);

   glEnd();

    glColor3f(.000, 0.0, 0.000);

   glBegin(GL_LINES);

    glVertex3f(46.f, 55.f, 0.0f);
	glVertex3f(46.f, 51.5f, 0.0f);

   glEnd();

      //get wall
    glColor3f(0.722, 0.525, 0.043);
    glBegin(GL_POLYGON);
    glVertex3f(15.0f, 34.0f, 0.0f);
    glVertex3f(15.0f, 37.0f, 0.0f);
    glVertex3f(35.5f, 37.0f, 0.0f);
    glVertex3f(35.5f, 34.0f, 0.0f);
    glEnd();
    //get gor

    glColor3f(.663, 0.663, 0.663);
    glBegin(GL_POLYGON);
    glVertex3f(31.0f, 34.0f, 0.0f);
    glVertex3f(31.0f, 40.0f, 0.0f);
    glVertex3f(35.0f, 40.0f, 0.0f);
    glVertex3f(35.0f, 34.0f, 0.0f);

    glEnd();
    //get-windo
    glColor3f(0.255, 0.412, 0.882);
    glBegin(GL_POLYGON);
    glVertex3f(32.5f, 35.0f, 0.0f);
    glVertex3f(32.5f, 38.0f, 0.0f);
    glVertex3f(33.5f, 38.0f, 0.0f);
    glVertex3f(33.5f, 35.0f, 0.0f);

    glEnd();
    glColor3f (0.0, 0.0, 0.0);

	glBegin(GL_LINES);

	glVertex3f(32.5f, 35.0f, 0.0f);
	glVertex3f(32.5f, 38.0f, 0.0f);

	glVertex3f(32.5f, 35.0f, 0.0f);
	glVertex3f(33.5f, 35.0f, 0.0f);

	glVertex3f(33.5f, 35.0f, 0.0f);
	glVertex3f(33.5f, 38.0f, 0.0f);

	glVertex3f(33.5f, 38.0f, 0.0f);
	glVertex3f(32.5f, 38.0f, 0.0f);

	glVertex3f(33.0f, 38.0f, 0.0f);
	glVertex3f(33.0f, 35.0f, 0.0f);

	  glEnd();

    glColor3f(0.0, 0.0, 0.0);
    glBegin(GL_POLYGON);
    glVertex3f(32.0f, 38.5f, 0.0f);
    glVertex3f(32.0f, 39.5f, 0.0f);
    glVertex3f(34.0f, 39.5f, 0.0f);
    glVertex3f(34.0f, 38.5f, 0.0f);

    glEnd();

     glColor3f(1.0, 1.0, 1.0);
    glBegin(GL_POLYGON);
    glVertex3f(32.5f, 38.75f, 0.0f);
    glVertex3f(32.5f, 39.5f, 0.0f);
    glVertex3f(33.5f, 39.5f, 0.0f);
    glVertex3f(33.5f, 38.75f, 0.0f);

    glEnd();
    glColor3f(0.184, 0.310, 0.310);
    glBegin(GL_POLYGON);
    glVertex3f(35.0f, 37.0f, 0.0f);
    glVertex3f(35.0f, 38.0f, 0.0f);
    glVertex3f(36.0f, 38.0f, 0.0f);
    glVertex3f(36.0f, 37.0f, 0.0f);

    glEnd();
    //get
    glColor3f(1.0, 1.0, 1.0);
    glBegin(GL_POLYGON);
    glVertex3f(35.5f, 34.0f, 0.0f);
    glVertex3f(35.5f, 37.0f, 0.0f);
    glVertex3f(42.5f, 37.0f, 0.0f);
    glVertex3f(42.5f, 34.0f, 0.0f);



    glEnd();
    //get line
    glColor3f (0.0, 0.0, 0.0);

	glBegin(GL_LINES);

	glVertex3f(35.5f, 34.0f, 0.0f);
	glVertex3f(35.5f, 37.0f, 0.0f);

	glVertex3f(35.5f, 34.0f, 0.0f);
	glVertex3f(42.5f, 34.0f, 0.0f);

	glVertex3f(42.5f, 34.0f, 0.0f);
	glVertex3f(42.5f, 37.0f, 0.0f);

	glVertex3f(42.5f, 37.0f, 0.0f);
	glVertex3f(35.5f, 37.0f, 0.0f);

	//get-line
	glVertex3f(35.0f, 34.0f, 0.0f);
	glVertex3f(35.0f, 37.0f, 0.0f);

	glVertex3f(35.5f, 34.0f, 0.0f);
	glVertex3f(35.5f, 37.0f, 0.0f);

	glVertex3f(36.f, 34.0f, 0.0f);
	glVertex3f(36.f, 37.0f, 0.0f);

	glVertex3f(36.5f, 34.0f, 0.0f);
	glVertex3f(36.5f, 37.0f, 0.0f);

	glVertex3f(37.0f, 34.0f, 0.0f);
	glVertex3f(37.0f, 37.0f, 0.0f);

	glVertex3f(37.5f, 34.0f, 0.0f);
	glVertex3f(37.5f, 37.0f, 0.0f);

	glVertex3f(38.f, 34.0f, 0.0f);
	glVertex3f(38.f, 37.0f, 0.0f);

	glVertex3f(38.5f, 34.0f, 0.0f);
	glVertex3f(38.5f, 37.0f, 0.0f);

	glVertex3f(39.f, 34.0f, 0.0f);
	glVertex3f(39.f, 37.0f, 0.0f);

	glVertex3f(39.5f, 34.0f, 0.0f);
	glVertex3f(39.5f, 37.0f, 0.0f);

	glVertex3f(40.0f, 34.0f, 0.0f);
	glVertex3f(40.0f, 37.0f, 0.0f);

  glVertex3f(40.5f, 34.0f, 0.0f);
	glVertex3f(40.5f, 37.0f, 0.0f);

	glVertex3f(41.0f, 34.0f, 0.0f);
	glVertex3f(41.0f, 37.0f, 0.0f);

	glVertex3f(41.5f, 34.0f, 0.0f);
	glVertex3f(41.5f, 37.0f, 0.0f);


	glVertex3f(42.0f, 34.0f, 0.0f);
	glVertex3f(42.0f, 37.0f, 0.0f);

	 glVertex3f(42.5f, 37.0f, 0.0f);
	 glVertex3f(35.5f, 34.0f, 0.0f);

	 glVertex3f(35.5f, 37.0f, 0.0f);
	  glVertex3f(42.5f, 34.0f, 0.0f);



	  glEnd();


	  //small-tree
	  glColor3f(0.000, 0.502, 0.000);
    glBegin(GL_POLYGON);
    glVertex3f(7.f, 29.5f, 0.0f);
    glVertex3f(6.f, 30.5f, 0.0f);
    glVertex3f(6.5f, 31.f, 0.0f);
    glVertex3f(7.f, 33.5f, 0.0f);
    glVertex3f(8.f, 32.5f, 0.0f);
    glVertex3f(9.f, 30.5f, 0.0f);
    glVertex3f(9.f, 29.5f, 0.0f);

  glEnd();

  glColor3f (0.184, 0.310, 0.310);

	glBegin(GL_LINES);

	glVertex3f(7.5f, 29.0f, 0.0f);
	glVertex3f(7.f, 30.5f, 0.0f);

	glVertex3f(7.5f, 29.0f, 0.0f);
	glVertex3f(7.5f, 30.5f, 0.0f);

	glVertex3f(7.5f, 29.0f, 0.0f);
	glVertex3f(8.f, 30.5f, 0.0f);

  glEnd();
  //smalltre-2


	  glColor3f(0.000, 0.502, 0.000);
    glBegin(GL_POLYGON);
    glVertex3f(13.f, 29.5f, 0.0f);
    glVertex3f(12.f, 30.5f, 0.0f);
    glVertex3f(12.5f, 31.f, 0.0f);
    glVertex3f(13.f, 33.5f, 0.0f);
    glVertex3f(14.f, 32.5f, 0.0f);
    glVertex3f(15.f, 30.5f, 0.0f);
    glVertex3f(15.f, 29.5f, 0.0f);

  glEnd();

   glColor3f (0.184, 0.310, 0.310);

	glBegin(GL_LINES);

	glVertex3f(13.5f, 29.0f, 0.0f);
	glVertex3f(13.f, 30.5f, 0.0f);

	glVertex3f(13.5f, 29.0f, 0.0f);
	glVertex3f(13.5f, 30.5f, 0.0f);

	glVertex3f(13.5f, 29.0f, 0.0f);
	glVertex3f(14.f, 30.5f, 0.0f);

  glEnd();

  //smalltre-3


	  glColor3f(0.000, 0.502, 0.000);
    glBegin(GL_POLYGON);
    glVertex3f(19.f, 29.5f, 0.0f);
    glVertex3f(18.f, 30.5f, 0.0f);
    glVertex3f(18.5f, 31.f, 0.0f);
    glVertex3f(19.f, 33.5f, 0.0f);
    glVertex3f(20.f, 32.5f, 0.0f);
    glVertex3f(21.f, 30.5f, 0.0f);
    glVertex3f(21.f, 29.5f, 0.0f);

  glEnd();

   glColor3f (0.184, 0.310, 0.310);

	glBegin(GL_LINES);

	glVertex3f(19.5f, 29.0f, 0.0f);
	glVertex3f(19.f, 30.5f, 0.0f);

	glVertex3f(19.5f, 29.0f, 0.0f);
	glVertex3f(19.5f, 30.5f, 0.0f);

	glVertex3f(19.5f, 29.0f, 0.0f);
	glVertex3f(20.f, 30.5f, 0.0f);

  glEnd();


  //smalltre-4


	  glColor3f(0.000, 0.502, 0.000);
    glBegin(GL_POLYGON);
    glVertex3f(25.f, 29.5f, 0.0f);
    glVertex3f(24.f, 30.5f, 0.0f);
    glVertex3f(24.5f, 31.f, 0.0f);
    glVertex3f(25.f, 33.5f, 0.0f);
    glVertex3f(26.f, 32.5f, 0.0f);
    glVertex3f(27.f, 30.5f, 0.0f);
    glVertex3f(27.f, 29.5f, 0.0f);

  glEnd();

   glColor3f (0.184, 0.310, 0.310);

	glBegin(GL_LINES);

	glVertex3f(25.5f, 29.0f, 0.0f);
	glVertex3f(25.f, 30.5f, 0.0f);

	glVertex3f(25.5f, 29.0f, 0.0f);
	glVertex3f(25.5f, 30.5f, 0.0f);

	glVertex3f(25.5f, 29.0f, 0.0f);
	glVertex3f(26.f, 30.5f, 0.0f);

  glEnd();


//smalltre-5


	  glColor3f(0.000, 0.502, 0.000);
    glBegin(GL_POLYGON);
    glVertex3f(31.f, 29.5f, 0.0f);
    glVertex3f(30.f, 30.5f, 0.0f);
    glVertex3f(30.5f, 31.f, 0.0f);
    glVertex3f(31.f, 33.5f, 0.0f);
    glVertex3f(32.f, 32.5f, 0.0f);
    glVertex3f(33.f, 30.5f, 0.0f);
    glVertex3f(33.f, 29.5f, 0.0f);

  glEnd();

   glColor3f (0.184, 0.310, 0.310);

	glBegin(GL_LINES);

	glVertex3f(31.5f, 29.0f, 0.0f);
	glVertex3f(31.f, 30.5f, 0.0f);

	glVertex3f(31.5f, 29.0f, 0.0f);
	glVertex3f(31.5f, 30.5f, 0.0f);

	glVertex3f(31.5f, 29.0f, 0.0f);
	glVertex3f(32.f, 30.5f, 0.0f);

  glEnd();




//smalltre-6


	  glColor3f(0.000, 0.502, 0.000);
    glBegin(GL_POLYGON);
    glVertex3f(37.f, 29.5f, 0.0f);
    glVertex3f(36.f, 30.5f, 0.0f);
    glVertex3f(36.5f, 31.f, 0.0f);
    glVertex3f(37.f, 33.5f, 0.0f);
    glVertex3f(38.f, 32.5f, 0.0f);
    glVertex3f(39.f, 30.5f, 0.0f);
    glVertex3f(39.f, 29.5f, 0.0f);

  glEnd();

   glColor3f (0.184, 0.310, 0.310);

	glBegin(GL_LINES);

	glVertex3f(37.5f, 29.0f, 0.0f);
	glVertex3f(37.f, 30.5f, 0.0f);

	glVertex3f(37.5f, 29.0f, 0.0f);
	glVertex3f(37.5f, 30.5f, 0.0f);

	glVertex3f(37.5f, 29.0f, 0.0f);
	glVertex3f(38.f, 30.5f, 0.0f);

  glEnd();


//smalltre-7


	  glColor3f(0.000, 0.502, 0.000);
    glBegin(GL_POLYGON);
    glVertex3f(43.f, 29.5f, 0.0f);
    glVertex3f(42.f, 30.5f, 0.0f);
    glVertex3f(42.5f, 31.f, 0.0f);
    glVertex3f(43.f, 33.5f, 0.0f);
    glVertex3f(44.f, 32.5f, 0.0f);
    glVertex3f(45.f, 30.5f, 0.0f);
    glVertex3f(45.f, 29.5f, 0.0f);

  glEnd();

   glColor3f (0.184, 0.310, 0.310);

	glBegin(GL_LINES);

	glVertex3f(43.5f, 29.0f, 0.0f);
	glVertex3f(43.f, 30.5f, 0.0f);

	glVertex3f(43.5f, 29.0f, 0.0f);
	glVertex3f(43.5f, 30.5f, 0.0f);

	glVertex3f(43.5f, 29.0f, 0.0f);
	glVertex3f(44.f, 30.5f, 0.0f);

  glEnd();


//smalltre-8


	  glColor3f(0.000, 0.502, 0.000);
    glBegin(GL_POLYGON);
    glVertex3f(49.f, 29.5f, 0.0f);
    glVertex3f(48.f, 30.5f, 0.0f);
    glVertex3f(48.5f, 31.f, 0.0f);
    glVertex3f(49.f, 33.5f, 0.0f);
    glVertex3f(50.f, 32.5f, 0.0f);
    glVertex3f(51.f, 30.5f, 0.0f);
    glVertex3f(51.f, 29.5f, 0.0f);

  glEnd();

   glColor3f (0.184, 0.310, 0.310);

	glBegin(GL_LINES);

	glVertex3f(49.5f, 29.0f, 0.0f);
	glVertex3f(49.f, 30.5f, 0.0f);

	glVertex3f(49.5f, 29.0f, 0.0f);
	glVertex3f(49.5f, 30.5f, 0.0f);

	glVertex3f(49.5f, 29.0f, 0.0f);
	glVertex3f(50.f, 30.5f, 0.0f);

  glEnd();


  //smalltre-9


	  glColor3f(0.000, 0.502, 0.000);
    glBegin(GL_POLYGON);
    glVertex3f(55.f, 29.5f, 0.0f);
    glVertex3f(54.f, 30.5f, 0.0f);
    glVertex3f(54.5f, 31.f, 0.0f);
    glVertex3f(55.f, 33.5f, 0.0f);
    glVertex3f(56.f, 32.5f, 0.0f);
    glVertex3f(57.f, 30.5f, 0.0f);
    glVertex3f(57.f, 29.5f, 0.0f);

  glEnd();

   glColor3f (0.184, 0.310, 0.310);

	glBegin(GL_LINES);

	glVertex3f(55.5f, 29.0f, 0.0f);
	glVertex3f(55.f, 30.5f, 0.0f);

	glVertex3f(55.5f, 29.0f, 0.0f);
	glVertex3f(55.5f, 30.5f, 0.0f);

	glVertex3f(55.5f, 29.0f, 0.0f);
	glVertex3f(56.f, 30.5f, 0.0f);

  glEnd();




//smalltre-10


	  glColor3f(0.000, 0.502, 0.000);
    glBegin(GL_POLYGON);
    glVertex3f(61.f, 29.5f, 0.0f);
    glVertex3f(60.f, 30.5f, 0.0f);
    glVertex3f(60.5f, 31.f, 0.0f);
    glVertex3f(61.f, 33.5f, 0.0f);
    glVertex3f(62.f, 32.5f, 0.0f);
    glVertex3f(63.f, 30.5f, 0.0f);
    glVertex3f(63.f, 29.5f, 0.0f);

  glEnd();

   glColor3f (0.184, 0.310, 0.310);

	glBegin(GL_LINES);

	glVertex3f(61.5f, 29.0f, 0.0f);
	glVertex3f(61.f, 30.5f, 0.0f);

	glVertex3f(61.5f, 29.0f, 0.0f);
	glVertex3f(61.5f, 30.5f, 0.0f);

	glVertex3f(61.5f, 29.0f, 0.0f);
	glVertex3f(62.f, 30.5f, 0.0f);

  glEnd();


  //smalltre-11


	  glColor3f(0.000, 0.502, 0.000);
    glBegin(GL_POLYGON);
    glVertex3f(67.f, 29.5f, 0.0f);
    glVertex3f(66.f, 30.5f, 0.0f);
    glVertex3f(66.5f, 31.f, 0.0f);
    glVertex3f(67.f, 33.5f, 0.0f);
    glVertex3f(68.f, 32.5f, 0.0f);
    glVertex3f(69.f, 30.5f, 0.0f);
    glVertex3f(69.f, 29.5f, 0.0f);

  glEnd();

   glColor3f (0.184, 0.310, 0.310);

	glBegin(GL_LINES);

	glVertex3f(67.5f, 29.0f, 0.0f);
	glVertex3f(67.f, 30.5f, 0.0f);

	glVertex3f(67.5f, 29.0f, 0.0f);
	glVertex3f(67.5f, 30.5f, 0.0f);

	glVertex3f(67.5f, 29.0f, 0.0f);
	glVertex3f(68.f, 30.5f, 0.0f);

  glEnd();


//smalltre-12


	  glColor3f(0.000, 0.502, 0.000);
    glBegin(GL_POLYGON);
    glVertex3f(73.f, 29.5f, 0.0f);
    glVertex3f(72.f, 30.5f, 0.0f);
    glVertex3f(72.5f, 31.f, 0.0f);
    glVertex3f(73.f, 33.5f, 0.0f);
    glVertex3f(74.f, 32.5f, 0.0f);
    glVertex3f(75.f, 30.5f, 0.0f);
    glVertex3f(75.f, 29.5f, 0.0f);

  glEnd();

   glColor3f (0.184, 0.310, 0.310);

	glBegin(GL_LINES);

	glVertex3f(73.5f, 29.0f, 0.0f);
	glVertex3f(73.f, 30.5f, 0.0f);

	glVertex3f(73.5f, 29.0f, 0.0f);
	glVertex3f(73.5f, 30.5f, 0.0f);

	glVertex3f(73.5f, 29.0f, 0.0f);
	glVertex3f(74.f, 30.5f, 0.0f);

  glEnd();

//smalltre-13


	  glColor3f(0.000, 0.502, 0.000);
    glBegin(GL_POLYGON);
    glVertex3f(79.f, 29.5f, 0.0f);
    glVertex3f(78.f, 30.5f, 0.0f);
    glVertex3f(78.5f, 31.f, 0.0f);
    glVertex3f(79.f, 33.5f, 0.0f);
    glVertex3f(80.f, 32.5f, 0.0f);
    glVertex3f(81.f, 30.5f, 0.0f);
    glVertex3f(81.f, 29.5f, 0.0f);

  glEnd();

   glColor3f (0.184, 0.310, 0.310);

	glBegin(GL_LINES);

	glVertex3f(79.5f, 29.0f, 0.0f);
	glVertex3f(79.f, 30.5f, 0.0f);

	glVertex3f(79.5f, 29.0f, 0.0f);
	glVertex3f(79.5f, 30.5f, 0.0f);

	glVertex3f(79.5f, 29.0f, 0.0f);
	glVertex3f(80.f, 30.5f, 0.0f);

  glEnd();

//smalltre-14


	  glColor3f(0.000, 0.502, 0.000);
    glBegin(GL_POLYGON);
    glVertex3f(85.f, 29.5f, 0.0f);
    glVertex3f(84.f, 30.5f, 0.0f);
    glVertex3f(84.5f, 31.f, 0.0f);
    glVertex3f(85.f, 33.5f, 0.0f);
    glVertex3f(86.f, 32.5f, 0.0f);
    glVertex3f(87.f, 30.5f, 0.0f);
    glVertex3f(87.f, 29.5f, 0.0f);

  glEnd();

   glColor3f (0.184, 0.310, 0.310);

	glBegin(GL_LINES);

	glVertex3f(85.5f, 29.0f, 0.0f);
	glVertex3f(85.f, 30.5f, 0.0f);

	glVertex3f(85.5f, 29.0f, 0.0f);
	glVertex3f(85.5f, 30.5f, 0.0f);

	glVertex3f(85.5f, 29.0f, 0.0f);
	glVertex3f(86.f, 30.5f, 0.0f);

  glEnd();

  //smalltre-15


	  glColor3f(0.000, 0.502, 0.000);
    glBegin(GL_POLYGON);
    glVertex3f(91.f, 29.5f, 0.0f);
    glVertex3f(90.f, 30.5f, 0.0f);
    glVertex3f(90.5f, 31.f, 0.0f);
    glVertex3f(91.f, 33.5f, 0.0f);
    glVertex3f(92.f, 32.5f, 0.0f);
    glVertex3f(93.f, 30.5f, 0.0f);
    glVertex3f(93.f, 29.5f, 0.0f);

  glEnd();

   glColor3f (0.184, 0.310, 0.310);

	glBegin(GL_LINES);

	glVertex3f(91.5f, 29.0f, 0.0f);
	glVertex3f(91.f, 30.5f, 0.0f);

	glVertex3f(91.5f, 29.0f, 0.0f);
	glVertex3f(91.5f, 30.5f, 0.0f);

	glVertex3f(91.5f, 29.0f, 0.0f);
	glVertex3f(92.f, 30.5f, 0.0f);

  glEnd();

    //smalltre-16


	  glColor3f(0.000, 0.502, 0.000);
    glBegin(GL_POLYGON);
    glVertex3f(97.f, 29.5f, 0.0f);
    glVertex3f(96.f, 30.5f, 0.0f);
    glVertex3f(96.5f, 31.f, 0.0f);
    glVertex3f(97.f, 33.5f, 0.0f);
    glVertex3f(98.f, 32.5f, 0.0f);
    glVertex3f(99.f, 30.5f, 0.0f);
    glVertex3f(99.f, 29.5f, 0.0f);

  glEnd();

   glColor3f (0.184, 0.310, 0.310);

	glBegin(GL_LINES);

	glVertex3f(97.5f, 29.0f, 0.0f);
	glVertex3f(97.f, 30.5f, 0.0f);

	glVertex3f(97.5f, 29.0f, 0.0f);
	glVertex3f(97.5f, 30.5f, 0.0f);

	glVertex3f(97.5f, 29.0f, 0.0f);
	glVertex3f(98.f, 30.5f, 0.0f);

  glEnd();

    //smalltre-left


	  glColor3f(0.000, 0.502, 0.000);
    glBegin(GL_POLYGON);
    glVertex3f(1.75f, 29.5f, 0.0f);
    glVertex3f(0.75f, 30.5f, 0.0f);
    glVertex3f(1.25f, 31.f, 0.0f);
    glVertex3f(1.75f, 33.5f, 0.0f);
    glVertex3f(2.75f, 32.5f, 0.0f);
    glVertex3f(3.75f, 30.5f, 0.0f);
    glVertex3f(3.75f, 29.5f, 0.0f);

  glEnd();

   glColor3f (0.184, 0.310, 0.310);

	glBegin(GL_LINES);

	glVertex3f(2.25f, 29.0f, 0.0f);
	glVertex3f(1.75f, 30.5f, 0.0f);

	glVertex3f(2.25f, 29.0f, 0.0f);
	glVertex3f(2.25f, 30.5f, 0.0f);

	glVertex3f(2.25f, 29.0f, 0.0f);
	glVertex3f(2.75f, 30.5f, 0.0f);

  glEnd();


    //SwimmingPool
    glColor3f (0.545, 0.271, 0.075);
    glBegin(GL_POLYGON);
    glVertex3f(80.0f, 2.0f, 0.0f);
    glVertex3f(80.0f, 27.0f, 0.0f);
    glVertex3f(97.0f, 27.0f, 0.0f);
    glVertex3f(97.0f, 2.0f, 0.0f);
    glEnd();

    glColor3f (0.000, 1.000, 1.000);
    glBegin(GL_POLYGON);
    glVertex3f(82.0f, 4.0f, 0.0f);
    glVertex3f(82.0f, 25.0f, 0.0f);
    glVertex3f(95.0f, 25.0f, 0.0f);
    glVertex3f(95.0f, 4.0f, 0.0f);
    glEnd();

    glColor3f (0.627, 0.322, 0.176);
    glBegin(GL_POLYGON);
    glVertex3f(80.0f, 2.0f, 0.0f);
    glVertex3f(80.0f, 0.0f, 0.0f);
    glVertex3f(97.0f, 0.0f, 0.0f);
    glVertex3f(97.0f, 2.0f, 0.0f);
    glEnd();

    glColor3f (0.627, 0.322, 0.176);
    glBegin(GL_POLYGON);
    glVertex3f(97.0f, 0.0f, 0.0f);
    glVertex3f(97.0f, 27.0f, 0.0f);
    glVertex3f(98.0f, 27.0f, 0.0f);
    glVertex3f(98.0f, 0.0f, 0.0f);
    glEnd();
    //SwimmingPool

    //Cloud
    glColor3f (1.000, 0.980, 0.980);
    glPushMatrix();
    glTranslatef(xpos, 0.0, 0.0);
    circle(15.0,71.0);
    circle(17.0,68.0);
    circle(13.0,68.0);


    circle(85.0,71.0);
    circle(83.0,68.0);
    circle(87.0,68.0);

    circle(40.0,81.0);
    circle(42.0,78.0);
    circle(38.0,78.0);

    circle(60.0,81.0);
    circle(62.0,78.0);
    circle(58.0,78.0);
    glPopMatrix();
    //Cloud







glFlush ();
}

void handleKeypress(unsigned char key, int x, int y) {
    if (key == 'd' || key == 'D') {
        isDay = !isDay;
    }
}


void init (void)
{
/* select clearing (background) color */
glClearColor (0.0, 0.0, 0.0, 0.0);
/* initialize viewing values */
glMatrixMode(GL_PROJECTION);
glLoadIdentity();
glOrtho(0.0, 100.0, 0.0, 100.0, -10.0, 10.0);
}
/*
* Declare initial window size, position, and display mode
* (single buffer and RGBA). Open window with "hello"
* in its title bar. Call initialization routines.
* Register callback function to display graphics.
* Enter main loop and process events.
*/
int main(int argc, char** argv)
{
glutInit(&argc, argv);
glutInitDisplayMode (GLUT_SINGLE | GLUT_RGB);
glutInitWindowSize (1200, 700);
glutInitWindowPosition (100, 100);
glutCreateWindow ("Green Campus");
init ();
glutDisplayFunc(display);
glutSpecialFunc(key);
glutIdleFunc(idle);
glutKeyboardFunc(handleKeypress);
glutMainLoop();
return 0;
}
