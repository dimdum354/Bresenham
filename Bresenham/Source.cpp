// Algoritma Bresenham

#include <GL\glut.h>
#include <iostream>

// Prosedur
void init();
void display();
void bresenham();

//  posisi window di layar
int window_x;
int window_y;

//  ukuran window
int window_width = 480;
int window_height = 480;

//  judul window
char *judul_window = "Algoritma Bresenham";

void main(int argc, char **argv)
{
	//  inisialisasi GLUT (OpenGL Utility Toolkit)
	glutInit(&argc, argv);
	// set posisi window supaya berada di tengah 
	window_x = (glutGet(GLUT_SCREEN_WIDTH) - window_width) / 2;
	window_y = (glutGet(GLUT_SCREEN_HEIGHT) - window_height) / 2;
	glutInitWindowSize(window_width, window_height); //set ukuran window 
	glutInitWindowPosition(window_x, window_y); //set posisi window

	glutInitDisplayMode(GLUT_RGBA | GLUT_DOUBLE); // set display RGB dan double buffer
	glutCreateWindow(judul_window); //set judul window


	init(); //jalankan fungsi init 
	glutDisplayFunc(display); //  set fungsi display
	glutMainLoop(); // set loop pemrosesan GLUT
}

void init()
{
	glClearColor(0.0, 0.0, 0.0, 0.0); //set warna background 
	glColor3f(1.0, 1.0, 1.0); //set warna titik
	glPointSize(2.0); //set ukuran titik
	glMatrixMode(GL_PROJECTION); //set mode matriks yang digunakan 
	glLoadIdentity(); // load matriks identitas
	gluOrtho2D(0.0, 800.0, 0.0, 600.0); // set ukuran viewing window
}
void display(void)
{
	glClear(GL_COLOR_BUFFER_BIT); //clear color
	bresenham(); //jalankan fungsi bresenham
	glutSwapBuffers(); //swap buffer 
}

void bresenham(void) {
	//tentukan titik awal dan akhir
	int x1 = 5;
	int y1 = 5;
	int x2 = 500;
	int y2 = 500;
	int i;
	double x, y, dx, dy, p;

	x = x1;
	y = y1;
	//hitung dx dan dy
	dx = x2 - x1;
	dy = y2 - y1;

	//hitung p 
	p = 2 * dy - dx;

	//tentukan titik awal dan akhir
	if (p<0) {
		x += 1;
		y;
		p = p + 2 * dy;
	}
	else {
		x += 1;
		y += 1;
		p = p + (2 * dy) - (2 * dx);
	}
	//gambar titik awal
	glBegin(GL_POINTS);
	glVertex2i(x, y);

	//perulangan untuk menggambar titik-titik 
	for (i = 0; i < p; i++) {
		x = x + 1;
		if (p<0) {
			x += 1;
			y;
			p = p + 2 * dy;
		}
		else {
			if (y1 > y2) {
				y = y - 1;
			}
			else {
				y = y + 1;
			}
			p = p + (2 * dy) - (2 * dx);

		}
		glVertex2i(x, y);

	}

	glEnd();
	glFlush();
}

