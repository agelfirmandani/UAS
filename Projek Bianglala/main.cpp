#include <windows.h>
#include <math.h>
#include <stdlib.h>
#include <GL/glut.h>
#include <stdio.h>
#include <math.h>
#include <GL/glut.h>
#include <string.h>
#include <assert.h>
#include <stdarg.h>

/**********************
 * Deklarasi variabel *
 **********************/
//Variable untuk manipulasi sudut pandang
static float angle=0.0,ratio;            //Sudut perputaran kamera (terhadap sumbu y)
static float x=0.0f,y=10.75f,z=55.0f;      //Posisi Kamera
static float lx=0.0f,ly=0.0f,lz=-1.0f;   //Vektor sudut pandang

float view_rotx = 0.0f, view_roty = 0.0f;
int oldMouseX, oldMouseY; //variable untuk function mousecontrol

//untuk perputaran bianglala
float qwe = 0;
float angl = 0;
void ada(){
     glPushMatrix();
        glTranslatef(0,0,0.5);
         glRotatef(qwe,0,0,1);
         glColor3f(2.0,1.0,1.1);
        glutSolidCone(5,3,50,4);
   qwe+=0.5;
    glPopMatrix();
    glPushMatrix();
        glTranslatef(0,0,-0.5);
         glRotatef(180,0,0,0);
         glRotatef(qwe,0,0,1);
         glColor3f(0.0,1.0,1.0);
        glutWireCone(5,3,50,4);
  qwe+=0.5;
    glPopMatrix();
    }

void duduk(){
     GLUquadric *quadric = gluNewQuadric();
     glPushMatrix();
        glColor3f(1.0,1.0,1.0);
       //tempat duduk
            glPushMatrix();
            glColor3f(1.0,0.3,2.0);
                glTranslatef(5,0,0);
                glRotatef(angl,0,0,1);
                glRotatef(270,1,0,0);
                gluCylinder(quadric, 0.5, 0.5, 1, 20, 20);
                glTranslatef(0,0,0.75);
                glutSolidOctahedron();
            glPopMatrix();
             glPushMatrix();
             glColor3f(0.3,1.0,0.5);
                glTranslatef(-5,0,0);
                glRotatef(angl,0,0,1);
                glRotatef(270,1,0,0);
                gluCylinder(quadric, 0.5, 0.5, 1, 20, 20);
                glTranslatef(0,0,0.75);
                glutSolidOctahedron();
            glPopMatrix();
             glPushMatrix();
             glColor3f(0.1,1.0,0.4);
                glTranslatef(0,5,0);
                glRotatef(angl,0,0,1);
                glRotatef(270,1,0,0);
                gluCylinder(quadric, 0.5, 0.5, 1, 20, 20);
                glTranslatef(0,0,0.75);
                glutSolidOctahedron();
            glPopMatrix();
             glPushMatrix();
             glColor3f(1.0,0.5,1.0);
                glTranslatef(0,-5,0);
                glRotatef(angl,0,0,1);
                glRotatef(270,1,0,0);
                gluCylinder(quadric, 0.5, 0.5, 1, 20, 20);
                glTranslatef(0,0,0.75);
                glutSolidOctahedron();
            glPopMatrix();
           glPushMatrix();
           glColor3f(1.0,0.0,0.0);
                glTranslatef(3.5,3.5,0);
                glRotatef(angl,0,0,1);
                glRotatef(270,1,0,0);
                gluCylinder(quadric, 0.5, 0.5, 1, 20, 20);
                glTranslatef(0,0,0.75);
                glutSolidOctahedron();
            glPopMatrix();
            glPushMatrix();
            glColor3f(0.8,0.5,0.0);
                glTranslatef(-3.5,3.5,0);
                glRotatef(angl,0,0,1);
                glRotatef(270,1,0,0);
                gluCylinder(quadric, 0.5, 0.5, 1, 20, 20);
                glTranslatef(0,0,0.75);
                glutSolidOctahedron();
            glPopMatrix();
            glPushMatrix();
            glColor3f(6.0,0.5,0.0);
                glTranslatef(3.5,-3.5,0);
                glRotatef(angl,0,0,1);
                glRotatef(270,1,0,0);
                gluCylinder(quadric, 0.5, 0.5, 1, 20, 20);
                glTranslatef(0,0,0.75);
                glutSolidOctahedron();
            glPopMatrix();
             glPushMatrix();
             glColor3f(0.5,0.7,1.0);
                glTranslatef(-3.5,-3.5,0);
                glRotatef(angl,0,0,1);
                glRotatef(270,1,0,0);
                gluCylinder(quadric, 0.5, 0.5, 1, 20, 20);
                glTranslatef(0,0,0.75);
                glutSolidOctahedron();
            glPopMatrix();
        glPopMatrix();
angl-=1;
}

void ass(){

    GLUquadric *quadric = gluNewQuadric();
    glPushMatrix();
        glColor3f(0.5,1.5,0.5);
        glTranslatef(0,0,-4);
        gluCylinder(quadric, 0.1, 0.1, 8, 20, 20);
    glPopMatrix();
}
void kaki(){
    GLUquadric *quadric = gluNewQuadric();
    glPushMatrix();
        glColor3f(0.5,0.5,0.5);
        glTranslatef(0,0,-4);
        glRotatef(90,1,0,0);
        gluCylinder(quadric, 0.1, 0.7, 5.5, 20, 20);
    glPopMatrix();
     glPushMatrix();
        glColor3f(0.5,0.5,0.5);
        glTranslatef(0,0,4);
        glRotatef(90,1,0,0);
        gluCylinder(quadric, 0.1, 0.7, 5.5, 20, 20);
    glPopMatrix();

}

void alas(){
     //Menggambar Tanah
     glColor3f(0.2, 4.5, 2.2);
	glBegin(GL_POLYGON);
           glTexCoord2f(0.0f,0.0f);
           glVertex3f(-2000.0f,0.0f,2000.0f);
           glTexCoord2f(5.0f,0.0f);
           glVertex3f(2000.0f,0.0f,2000.0f);
           glTexCoord2f(5.0f,5.0f);
           glVertex3f(2000.0f,0.0f,-2000.0f);
           glTexCoord2f(0.0f,5.0f);
           glVertex3f(-2000.0f,0.0f,-2000.0f);

        glEnd();
     glPopMatrix();
     }

void renderScene(void) {
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    /////////////////bianglala////////////////////////
    glPushMatrix();
    alas();
    glPopMatrix();
    glPushMatrix();
                   glTranslatef(-5,17,-10);
                   glScalef(3,3,3);
                   glRotatef(150,0,1,0);
                   ada();
                   ass();
                   kaki();
                   glPushMatrix();
                        glRotatef(qwe,0,0,1);
                        duduk();
                   glPopMatrix();
                   glColor3f(1.0,1.0,1.0);
   glPopMatrix();
   /////////////////bianglala////////////////////////

	//Menggambar Halaman
	glColor3f(0, 1, 0);
	glBegin(GL_QUADS);
		glVertex3f(-40.0, 0.1, -40.0);
		glVertex3f(-40.0, 0.1,  40.0);
		glVertex3f( 40.0, 0.1,  40.0);
		glVertex3f( 40.0, 0.1, -40.0);
	glEnd();

	glRotatef(view_rotx, 0.0f, 1.0f, 0.0f);
    glRotatef(view_roty, 0.0f, 1.0f, 0.0f);

    glutSwapBuffers();
}

// Fungsi untuk menyesuaikan perspektif ketika window dirubah ukurannya
void changeSize(int w, int h) {

	// Menghindari pembagian oleh 0.
	if(h == 0)
		h = 1;

    // Rasio antara lebar dengan tinggi layar
	float ratio = 1.0* w / h;

	// Reset the coordinate system before modifying
	glMatrixMode(GL_PROJECTION); //Matrik diset : Matrik Proyeksi
	glLoadIdentity();            //Meload matrik identitas

	// Set the viewport to be the entire window (titik pusat ruang pandang)
	glViewport(0, 0, w, h);

	// Set the correct perspective.
	gluPerspective(45,ratio,1,1000); //Parameter perspektif (sudut di sumbu yz, rasio lebar/tinggi,
                                     //near clipping planes, far clipping plane)
	glMatrixMode(GL_MODELVIEW);      //Set matrix ke GL_MODELVIEW
	glLoadIdentity();                //Load identity matrix

    //gluLookAt
    gluLookAt(x     , y    , z,
              x + lx,y + ly,z + lz,
		      0.0f  ,1.0f  ,0.0f);

}

void orientMe(float ang) {

	lx = sin(ang);
	lz = -cos(ang);
	glLoadIdentity();
	gluLookAt(x, y, z,
		      x + lx,y + ly,z + lz,
			  0.0f,1.0f,0.0f);
}

void moveMeFlat(int direction) {
	x = x + direction*(lx)*0.1;
	z = z + direction*(lz)*0.1;

	glLoadIdentity();
	gluLookAt(x, y, z,
		      x + lx,y + ly,z + lz,
			  0.0f,1.0f,0.0f);
}

void inputKey(int key, int x, int y) {

	switch (key) {
		case GLUT_KEY_LEFT :
			angle -= 0.05f;
			orientMe(angle);break;
		case GLUT_KEY_RIGHT :
			angle +=0.05f;
			orientMe(angle);break;
		case GLUT_KEY_UP :
			     moveMeFlat(5);break;
		case GLUT_KEY_DOWN :
			     moveMeFlat(-5);break;
	}
}

const GLfloat light_ambient[]  = { 0.0f, 0.0f, 0.0f, 1.0f };
const GLfloat light_diffuse[]  = { 1.0f, 1.0f, 1.0f, 1.0f };
const GLfloat light_specular[] = { 1.0f, 1.0f, 1.0f, 1.0f };
const GLfloat light_position[] = { 2.0f, 5.0f, 5.0f, 0.0f };

const GLfloat mat_ambient[]    = { 0.7f, 0.7f, 0.7f, 1.0f };
const GLfloat mat_diffuse[]    = { 0.8f, 0.8f, 0.8f, 1.0f };
const GLfloat mat_specular[]   = { 1.0f, 1.0f, 1.0f, 1.0f };
const GLfloat high_shininess[] = { 100.0f };

void mouseControl(int button, int state, int x, int y){
    oldMouseX = x;
    oldMouseY = y;
    }

void mouseMotion(int x, int y){
    int getX = x;
    int getY = y;
    float thetaY = 0.1f*(getX - oldMouseX)/380;
    float thetaX = 0.1f*(getY - oldMouseY)/380;
    oldMouseX = getX;
    oldMouseY = getY;
    view_rotx += thetaX;
    view_roty += thetaY;
    }
//Fungsi utama
int main(int argc, char **argv) {
     //argc -> a pointer to the unmodified argc variable from the main function
     //argv -> a pointer to the unmodified argv variable from the main function
     glutInit(&argc, argv);

     glutInitDisplayMode(GLUT_DEPTH | GLUT_DOUBLE | GLUT_RGBA);

     //Parameter posisi window (x,y)
     glutInitWindowPosition(100,100);

     //Parameter ukuran window (panjang,lebar)
	 glutInitWindowSize(640,360);

     //Membuat windows Latihan
	 glutCreateWindow("Anting - anting");

     glClearColor( 0.1, 0.5, 1, 0);
     //Fungsi utama untuk menampilkan objek
     glutDisplayFunc(renderScene);

     //Mengaktifkan fungsi kontrol mouse
     glutMouseFunc(mouseControl);
     glutMotionFunc(mouseMotion);


     //Fungsi yang dijalankan dalam keadaan idle
     glutIdleFunc(renderScene);

     //Fungsi untuk mengatur perspektif.
     //Untuk mempertahankan ukuran objek saat jendela dirubah ukurannya
     glutReshapeFunc(changeSize);

     glutSpecialFunc(inputKey);

     //Mengaktifkan depth testing
     glEnable(GL_DEPTH_TEST);
    //Mengatur Pencahayaan
    glDepthFunc(GL_LESS);

   glEnable(GL_LIGHT0);
    glEnable(GL_NORMALIZE);
    glEnable(GL_COLOR_MATERIAL);
    glEnable(GL_LIGHTING);

    glLightfv(GL_LIGHT0, GL_AMBIENT,  light_ambient);
    glLightfv(GL_LIGHT0, GL_DIFFUSE,  light_diffuse);
    glLightfv(GL_LIGHT0, GL_SPECULAR, light_specular);
    glLightfv(GL_LIGHT0, GL_POSITION, light_position);

    glMaterialfv(GL_FRONT, GL_AMBIENT,   mat_ambient);
    glMaterialfv(GL_FRONT, GL_DIFFUSE,   mat_diffuse);
    glMaterialfv(GL_FRONT, GL_SPECULAR,  mat_specular);
    glMaterialfv(GL_FRONT, GL_SHININESS, high_shininess);
     //Never ending loop, agar layar tidak langsung tertutup
 	 glutMainLoop();

}
