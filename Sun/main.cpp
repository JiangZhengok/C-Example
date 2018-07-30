#include <glut.h>
#include <stdlib.h>
#include "math.h"
#include <gl\glaux.h>	// GLaux库的头文件
#pragma comment( lib, "glaux.lib")		// GLaux连接库

//行星序是水星、金星、地球、火星、木星、土星、天王星、和海王星
//adam,hesper,earth,mars,jupiter,saturn,uranus,neptune
static int year = 0, day = 0,adamYear=0,hesperYear=0,marsYear=0,jupiterYear=0,saturnYear=0,uranusYear=0,neptuneYear=0,sunYear=0;
float light_angle=0;
float light_radius=8.0;
float cam_radius=7.0;
float cam_radius1;
float cam_position[3];
float cam_angle_u=0.3;
float cam_angle_v=0.3;
int state=1;
float star[2000][3];

UINT g_cactus[16];	//贴图
GLUquadricObj *g_text;

void lPosition();
void cPosition();
bool LoadT8(LPCWSTR filename, GLuint &texture);

void init(void)
{
	glClearColor (0.0, 0.0, 0.0, 0.0);

	lPosition();
	glShadeModel (GL_SMOOTH);
	glEnable(GL_LIGHTING);
	glEnable(GL_LIGHT0);
	glEnable(GL_DEPTH_TEST);
	glEnable(GL_COLOR_MATERIAL);

    g_text = gluNewQuadric();
	LPCWSTR filename=_T("sun.bmp");
	LoadT8(filename,g_cactus[0]);//帖图
	filename=_T("adam.bmp");
	LoadT8(filename,g_cactus[1]);//帖图
	filename=_T("hesper.bmp");
	LoadT8(filename,g_cactus[2]);//帖图
	filename=_T("earth.bmp");
	LoadT8(filename,g_cactus[3]);//帖图
	filename=_T("mars.bmp");
	LoadT8(filename,g_cactus[4]);//帖图
	filename=_T("jupiter.bmp");
	LoadT8(filename,g_cactus[5]);//帖图
	filename=_T("saturn.bmp");
	LoadT8(filename,g_cactus[6]);//帖图uranus.bmp
	filename=_T("uranus.bmp");
	LoadT8(filename,g_cactus[7]);//帖图Neptune
	filename=_T("neptune.bmp");
	LoadT8(filename,g_cactus[8]);//帖图Neptune
}
void init_stars()
{
	for ( int i=0; i < 2000; i++ )
	{
		for(int j=0;j<3;j++)
		{
			star[i][j]=rand()%20-10;
		}
	}
}

bool LoadT8(LPCWSTR filename, GLuint &texture)//调8位贴图
{
	AUX_RGBImageRec *pImage = NULL;
	LPCWSTR file=(LPCWSTR)filename;
	pImage = auxDIBImageLoad(filename);			// 装入位图
	if(pImage == NULL)		return false;		// 确保位图数据已经装入
	glGenTextures(1, &texture);					// 生成纹理
	glBindTexture    (GL_TEXTURE_2D,texture);	// 捆绑纹理
	gluBuild2DMipmaps(GL_TEXTURE_2D,4, pImage->sizeX,
					  pImage->sizeY,GL_RGB, GL_UNSIGNED_BYTE,pImage->data);
	glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MIN_FILTER,GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MAG_FILTER,GL_LINEAR);
	free(pImage->data);	//释放位图占据的内存资源
	free(pImage);
	return true;// 返回true
}


void material_sun()
{
	GLfloat mat_specular[] = { 1.0, 1.0, 1.0, 1.0 };
	GLfloat mat_shininess[] = { 50.0 };
	GLfloat lmodel_ambient[]={1.0,0.0,0.0,1.0};
	GLfloat white_light[]={1.0, 1.0,1.0, 1.0};

	glMaterialfv(GL_FRONT, GL_SPECULAR, mat_specular);
	glMaterialfv(GL_FRONT, GL_SHININESS, mat_shininess);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, lmodel_ambient);
	glLightModelfv(GL_LIGHT_MODEL_AMBIENT, lmodel_ambient);
}

void material_earth()
{
	GLfloat mat_specular[] = { 1.0, 1.0, 1.0, 1.0 };
	GLfloat mat_shininess[] = { 50.0 };
	GLfloat lmodel_ambient[]={0.0,1.0,0.0,1.0};
	GLfloat white_light[]={1.0, 1.0,1.0, 1.0};

	glMaterialfv(GL_FRONT, GL_SPECULAR, mat_specular);
	glMaterialfv(GL_FRONT, GL_SHININESS, mat_shininess);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, lmodel_ambient);
	glLightModelfv(GL_LIGHT_MODEL_AMBIENT, lmodel_ambient);
}

 void stars()
{
	glBegin( GL_POINTS );
	glColor3f( 1.0f, 1.0f, 1.0f );
	for ( int i=0; i < 2000; ++i )
	{
			glVertex3f( star[i][0], star[i][1], star[i][2] );
	}
	glEnd();
}

void sun()
{
	glPushMatrix();
	glBindTexture(GL_TEXTURE_2D, g_cactus[0]);//
	gluSphere(g_text,0.6, 32, 32);   /* draw sun */
	gluQuadricTexture(g_text,GLU_TRUE);              //建立纹理坐标
	gluQuadricDrawStyle(g_text,GLU_FILL);            //用面填充
	glPopMatrix();
}

void adam()
{
	glPushMatrix();
	glBindTexture(GL_TEXTURE_2D, g_cactus[1]);//
	glRotatef ((GLfloat) adamYear, 0.0, 0.0, 1.0);
	glTranslatef (0.8, 0.0, 0.0);
	glRotatef ((GLfloat) day, 0.0, 0.0, 1.0);
	gluSphere(g_text,0.13, 20, 16);    /* draw smaller planet */
	glPopMatrix();
}
void hesper()
{
	glPushMatrix();
	glBindTexture(GL_TEXTURE_2D, g_cactus[2]);//
	glRotatef ((GLfloat)hesperYear, 0.0, 0.0, 1.0);
	glTranslatef (1.3, 0.0, 0.0);
	glRotatef ((GLfloat) day, 0.0, 0.0, 1.0);
	gluSphere(g_text,0.2, 20, 16);    /* draw smaller planet */
	glPopMatrix();
}
void earth()
{
	glPushMatrix();
	glBindTexture(GL_TEXTURE_2D, g_cactus[3]);//
	glRotatef ((GLfloat) year, 0.0, 0.0, 1.0);
	glTranslatef (1.8, 0.0, 0.0);
	glRotatef ((GLfloat) day, 0.0, 0.0, 1.0);
	//material_earth();
	//gluQuadricTexture(g_text,GLU_TRUE);              //建立纹理坐标
	//gluQuadricDrawStyle(g_text,GLU_FILL);            //用面填充
	gluSphere(g_text,0.16, 20, 16);    /* draw smaller planet */

	glPopMatrix();
}
void mars()
{
	glPushMatrix();
	glBindTexture(GL_TEXTURE_2D, g_cactus[4]);//
	glRotatef ((GLfloat)marsYear, 0.0, 0.0, 1.0);
	glTranslatef (2.2, 0.0, 0.0);
	glRotatef ((GLfloat) day, 0.0, 0.0, 1.0);
	gluSphere(g_text,0.14, 20, 16);    /* draw smaller planet */
	glPopMatrix();
}
void jupiter()
{
	glPushMatrix();
	glBindTexture(GL_TEXTURE_2D, g_cactus[5]);//
	glRotatef ((GLfloat)jupiterYear, 0.0, 0.0, 1.0);
	glTranslatef (2.7, 0.0, 0.0);
	glRotatef ((GLfloat) day, 0.0, 0.0, 1.0);
	gluSphere(g_text,0.22, 20, 16);    /* draw smaller planet */
	glPopMatrix();
}
void park()
{
	glBegin(GL_TRIANGLE_FAN);
	glVertex3f(0,0,0);
	for(int i=0;i<=380;i+=20)
	{
		float p=(float)(i*3.14/180);
		glVertex3f((float)sin(p)*0.22,(float)cos(p)*0.22,0.0f);
	}
	glEnd();
}
void saturn()
{
	glPushMatrix();
	glBindTexture(GL_TEXTURE_2D, g_cactus[6]);//
	glRotatef ((GLfloat) saturnYear, 0.0, 0.0, 1.0);
	glTranslatef (3.15, 0.0, 0.0);
	glRotatef ((GLfloat) day, 0.0, 0.0, 1.0);
	gluSphere(g_text,0.14, 20, 16);    /* draw smaller planet */
	glRotatef (0.2, 1.0, 0.0, 0.0);
	//auxSolidCylinder(0.15,0.01)
	park();
	glPopMatrix();
}

void uranus()
{
	glPushMatrix();
	glBindTexture(GL_TEXTURE_2D, g_cactus[7]);//
	glRotatef ((GLfloat) uranusYear, 0.0, 0.0, 1.0);
	glTranslatef (3.55, 0.0, 0.0);
	glRotatef ((GLfloat) day, 0.0, 0.0, 1.0);
	gluSphere(g_text,0.12, 20, 16);    /* draw smaller planet */
	glPopMatrix();
}
void neptune()
{
	glPushMatrix();
	glBindTexture(GL_TEXTURE_2D, g_cactus[8]);//
	glRotatef ((GLfloat) neptuneYear, 0.0, 0.0, 1.0);
	glTranslatef (3.8, 0.0, 0.0);
	glRotatef ((GLfloat) day, 0.0, 0.0, 1.0);
	gluSphere(g_text,0.10, 20, 16);    /* draw smaller planet */
	glPopMatrix();
}
void lPosition()
{
	float y,z;
	y=light_radius*cos(light_angle);
	z=light_radius*sin(light_angle);
	float light_position[] = { 3.0,y,z, 0.0 };
	glLightfv(GL_LIGHT0, GL_POSITION, light_position);
}
void display(void)
{
	lPosition();

	///////////////////////////////////////////////////////////////////////////////////////////////////////
	glClear (GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
	glColor3f (1.0, 1.0, 1.0);
	glTexGeni(GL_S,GL_TEXTURE_GEN_MODE,GL_OBJECT_LINEAR);			//Texturing Contour Anchored To The Object
	glTexGeni(GL_T,GL_TEXTURE_GEN_MODE,GL_OBJECT_LINEAR);			//Texturing Contour Anchored To The Object

	//glEnable(GL_TEXTURE_GEN_S);										//Auto Texture Generation
	//glEnable(GL_TEXTURE_GEN_T);										//Auto Texture Generation
	glEnable(GL_TEXTURE_2D);
	///////////////////////////////////////////////////////////////////////////////////////////////////////
	stars();
	//glBindTexture(GL_TEXTURE_2D, g_cactus[1]);
	//gluSphere(g_text,0.4,48,48);
	stars();
	sun();
	adam();
	hesper();
	earth();
	mars();
	jupiter();
	saturn();
	uranus();
	neptune();
	///////////////////////////////////////////////////////////////////////////////////////////////////////
	glDisable(GL_TEXTURE_2D);
	//glDisable(GL_TEXTURE_GEN_S);										//Auto Texture Generation
	//glDisable(GL_TEXTURE_GEN_T);
	glutSwapBuffers();
}

void cPosition()
{
	cam_radius1=cam_radius*cos(cam_angle_v);
	cam_position[0]=cam_radius1*cos(cam_angle_u);
	cam_position[1]=cam_radius1*sin(cam_angle_u);
	cam_position[2]=cam_radius*sin(cam_angle_v);
	glLoadIdentity();
	gluLookAt(cam_position[0],cam_position[1],cam_position[2], 0.0, 0.0, 0.0, 0.0, 0.0, 1.0);
}

void reshape (int w, int h)
{
   glViewport (0, 0, (GLsizei) w, (GLsizei) h);
   glMatrixMode (GL_PROJECTION);
   glLoadIdentity ();
   gluPerspective(60.0, (GLfloat) w/(GLfloat) h, 1.0, 20.0);
   glMatrixMode(GL_MODELVIEW);
   cPosition();
}

void move()
{
	//adamYear=0,hesperYear=0,marsYear=0,jupiterYear=0,saturnYear=0,uranusYear=0,neptuneYear=0;
	adamYear=(adamYear+12)%360;
	hesperYear=(hesperYear+20)%360;
	year=(year+8)%360;
	marsYear=(marsYear+6)%360;
	jupiterYear=(jupiterYear+5)%360;
	saturnYear=(saturnYear+4)%360;
	uranusYear=(uranusYear+3)%360;
	neptuneYear=(neptuneYear+1)%360;
	day = (day + 30) % 360;
}
void move1()
{
	//adamYear=0,hesperYear=0,marsYear=0,jupiterYear=0,saturnYear=0,uranusYear=0,neptuneYear=0;
	adamYear=(adamYear-12)%360;
	hesperYear=(hesperYear-20)%360;
	year=(year-8)%360;
	marsYear=(marsYear-6)%360;
	jupiterYear=(jupiterYear-5)%360;
	saturnYear=(saturnYear-4)%360;
	uranusYear=(uranusYear-3)%360;
	neptuneYear=(neptuneYear-1)%360;
	day = (day - 30) % 360;
}
void keyboard (unsigned char key, int x, int y)
{
   switch (key) {
      case 'f':
         day = (day + 10) % 360;
         glutPostRedisplay();
         break;
      case 'F':
         day = (day - 10) % 360;
         glutPostRedisplay();
         break;
      case 'y':
         year = (year + 5) % 360;
         glutPostRedisplay();
         break;
      case 'Y':
         year = (year - 5) % 360;
         glutPostRedisplay();
         break;
	  case 'l':
		  light_angle+=2.0/90;
		 // if(light_position1>1.0)light_position1=0.0;
		  glutPostRedisplay();
		  break;
		case 'L':
		  light_angle-=2.0/90;
		 // if(light_position1>1.0)light_position1=0.0;
		  glutPostRedisplay();
		  break;
	  case 'k':
		 cam_radius+=0.2;
		 cPosition();
		 glutPostRedisplay();
		/*glLoadIdentity();
		camera_position+=0.1;
		gluLookAt(camera_position,camera_position, 5.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0);*/
		glutPostRedisplay();
		break;
	 case 'K':
		cam_radius-=0.2;
		cPosition();
		glutPostRedisplay();
		/*glLoadIdentity();
		camera_position-=0.1;
		gluLookAt(camera_position,camera_position, 5.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0);*/
		glutPostRedisplay();
		break;
	 case'w':
		cam_angle_v+=1.0/30;
		 if(cam_angle_v>1.0)
		 {
			 cam_angle_v=1.0;
		 }
		cPosition();
		glutPostRedisplay();
		break;
	 case's':
		cam_angle_v-=1.0/30;
		 if(cam_angle_v<-1.0)
		 {
			 cam_angle_v=-1.0;
		 }
		cPosition();
		glutPostRedisplay();
		break;
	 case'a':
		cam_angle_u+=1.0/30;
		cPosition();
		glutPostRedisplay();
		break;
	 case'd':
		cam_angle_u-=1.0/30;
		cPosition();
		glutPostRedisplay();
		break;
	 case'r':
		cam_radius=5.0;
		cam_angle_u=0;
		cam_angle_v=0;
		cPosition();
		glutPostRedisplay();
		break;
	 case'q':
		move();
		glutPostRedisplay();
		break;
	 case'Q':
		move1();
		glutPostRedisplay();
		break;
	 case 27:
		 exit(0);
		 break;
      default:
         break;
   }
}

int main(int argc, char** argv)
{
   glutInit(&argc, argv);
   glutInitDisplayMode (GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
   glutInitWindowSize (800, 600);
   glutInitWindowPosition (100, 100);
   glutCreateWindow (argv[0]);
   init ();
   init_stars();
   glutDisplayFunc(display);
   glutReshapeFunc(reshape);
   glutKeyboardFunc(keyboard);
   glutMainLoop();
   return 0;
}
