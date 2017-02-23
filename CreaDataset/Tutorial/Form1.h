#pragma once
#include "stdafx.h"
#include "ImageProcess.hpp"
#include <fstream>
#include <iostream>
#include <string>
#include <fstream>
//#include <Windows.h>

//#include <mmsystem.h>  

using namespace System;
using namespace System::ComponentModel;
using namespace System::Collections;
using namespace System::Windows::Forms;
using namespace System::Data;
using namespace System::Drawing;
//using namespace cv;
using namespace std;

string inttostr(int input);
string GetStdoutFromCommand(string cmd);
string RemoveChar(string str, char c);
void createSynsetWord();

//initialize component here to get access public class
CvCapture* capture;
IplImage* frame;
IplImage *mouthRegion;

ObjectDetector* faceDetector = new HaarCascadeObjectDetector("haarcascade_frontalface_alt.xml");
//Console::WriteLine(L"Hello World");
//Mat im = imread("lena.jpg");

IplImage* result;
Rect croppedRectangle;
int key;
long int framenumber = 0;
bool mouthFound = false;
Mat myMat;
Mat croppedImage;
bool inizia = false;

bool camera_on = false;

int photocount = 0; //initialize image counter

int N_MIN = 0;
int regola_index = 0; // per stabilire tramite pulsanti quale classe classificare
int NUM_CLASSI = 9;

fstream f("train.txt", ios::out); //apre il file in scrittura (cancellando quello che già c'era

__int32 num_item_per_class;

int fino_a = 0;
int conta = 0;

namespace Tutorial {


	/// <summary>
	/// Summary for Form1
	/// </summary>
	public ref class Form1 : public System::Windows::Forms::Form
	{
	public:
		Form1(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~Form1()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::PictureBox^  pictureBox1;
	protected: 
	private: System::Windows::Forms::Button^  button1;
	private: System::Windows::Forms::Timer^  timer1;
	private: System::Windows::Forms::MenuStrip^  menuStrip1;
	private: System::Windows::Forms::ToolStripMenuItem^  fileToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  exitToolStripMenuItem;
	private: System::Windows::Forms::TextBox^  textBox1;
	public: System::Windows::Forms::PictureBox^  pictureBox2;
	private: System::Windows::Forms::Button^  button2;
	private: System::Windows::Forms::ListView^  listView1;
	private: System::Windows::Forms::ColumnHeader^  Classe;
	private: System::Windows::Forms::TextBox^  textBox2;
	private: System::Windows::Forms::Label^  label1;
	private: System::Windows::Forms::Label^  label2;
	private: System::Windows::Forms::Label^  label3;
	private: System::Windows::Forms::Button^  buttonSU;
	private: System::Windows::Forms::Button^  buttonGIU;



	private: System::ComponentModel::IContainer^  components;

	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>


#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->components = (gcnew System::ComponentModel::Container());
			System::ComponentModel::ComponentResourceManager^  resources = (gcnew System::ComponentModel::ComponentResourceManager(Form1::typeid));
			System::Windows::Forms::ListViewItem^  listViewItem1 = (gcnew System::Windows::Forms::ListViewItem(L"0 - A,L,N,NE,VA,CA"));
			System::Windows::Forms::ListViewItem^  listViewItem2 = (gcnew System::Windows::Forms::ListViewItem(L"1 - E,CA,GA,CHE,F,FI"));
			System::Windows::Forms::ListViewItem^  listViewItem3 = (gcnew System::Windows::Forms::ListViewItem(L"2 - I,CHI,BI,R,S,T,D,GR,Z"));
			System::Windows::Forms::ListViewItem^  listViewItem4 = (gcnew System::Windows::Forms::ListViewItem(L"3 - O,GO,CO,DO,PO,TO,RO"));
			System::Windows::Forms::ListViewItem^  listViewItem5 = (gcnew System::Windows::Forms::ListViewItem(L"4 - U,QU,Gu,TU,SU,LU"));
			System::Windows::Forms::ListViewItem^  listViewItem6 = (gcnew System::Windows::Forms::ListViewItem(L"5 - F,V"));
			System::Windows::Forms::ListViewItem^  listViewItem7 = (gcnew System::Windows::Forms::ListViewItem(L"6 - T,D,Z,S,R"));
			System::Windows::Forms::ListViewItem^  listViewItem8 = (gcnew System::Windows::Forms::ListViewItem(L"7 - P,M,B"));
			System::Windows::Forms::ListViewItem^  listViewItem9 = (gcnew System::Windows::Forms::ListViewItem(L"8 - CI,GI,CE,GE,SH"));
			System::Windows::Forms::ListViewItem^  listViewItem10 = (gcnew System::Windows::Forms::ListViewItem(L"9 - NEUT"));
			this->pictureBox1 = (gcnew System::Windows::Forms::PictureBox());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->timer1 = (gcnew System::Windows::Forms::Timer(this->components));
			this->menuStrip1 = (gcnew System::Windows::Forms::MenuStrip());
			this->fileToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->exitToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->pictureBox2 = (gcnew System::Windows::Forms::PictureBox());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->listView1 = (gcnew System::Windows::Forms::ListView());
			this->Classe = (gcnew System::Windows::Forms::ColumnHeader());
			this->textBox2 = (gcnew System::Windows::Forms::TextBox());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->buttonSU = (gcnew System::Windows::Forms::Button());
			this->buttonGIU = (gcnew System::Windows::Forms::Button());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->BeginInit();
			this->menuStrip1->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox2))->BeginInit();
			this->SuspendLayout();
			// 
			// pictureBox1
			// 
			this->pictureBox1->BackColor = System::Drawing::Color::Black;
			this->pictureBox1->BorderStyle = System::Windows::Forms::BorderStyle::Fixed3D;
			this->pictureBox1->Location = System::Drawing::Point(12, 70);
			this->pictureBox1->Name = L"pictureBox1";
			this->pictureBox1->Size = System::Drawing::Size(320, 240);
			this->pictureBox1->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->pictureBox1->TabIndex = 0;
			this->pictureBox1->TabStop = false;
			// 
			// button1
			// 
			this->button1->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"button1.BackgroundImage")));
			this->button1->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->button1->Font = (gcnew System::Drawing::Font(L"Courier New", 9.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->button1->ForeColor = System::Drawing::SystemColors::ControlLightLight;
			this->button1->Location = System::Drawing::Point(338, 70);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(78, 69);
			this->button1->TabIndex = 1;
			this->button1->Text = L"ON";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &Form1::button1_Click);
			// 
			// timer1
			// 
			this->timer1->Interval = 30;
			this->timer1->Tick += gcnew System::EventHandler(this, &Form1::timer1_Tick);
			// 
			// menuStrip1
			// 
			this->menuStrip1->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(1) { this->fileToolStripMenuItem });
			this->menuStrip1->Location = System::Drawing::Point(0, 0);
			this->menuStrip1->Name = L"menuStrip1";
			this->menuStrip1->Size = System::Drawing::Size(703, 24);
			this->menuStrip1->TabIndex = 3;
			this->menuStrip1->Text = L"menuStrip1";
			// 
			// fileToolStripMenuItem
			// 
			this->fileToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(1) { this->exitToolStripMenuItem });
			this->fileToolStripMenuItem->Name = L"fileToolStripMenuItem";
			this->fileToolStripMenuItem->Size = System::Drawing::Size(37, 20);
			this->fileToolStripMenuItem->Text = L"File";
			// 
			// exitToolStripMenuItem
			// 
			this->exitToolStripMenuItem->Name = L"exitToolStripMenuItem";
			this->exitToolStripMenuItem->Size = System::Drawing::Size(92, 22);
			this->exitToolStripMenuItem->Text = L"Exit";
			this->exitToolStripMenuItem->Click += gcnew System::EventHandler(this, &Form1::exitToolStripMenuItem_Click);
			// 
			// textBox1
			// 
			this->textBox1->Location = System::Drawing::Point(12, 316);
			this->textBox1->Multiline = true;
			this->textBox1->Name = L"textBox1";
			this->textBox1->ScrollBars = System::Windows::Forms::ScrollBars::Vertical;
			this->textBox1->Size = System::Drawing::Size(373, 190);
			this->textBox1->TabIndex = 4;
			// 
			// pictureBox2
			// 
			this->pictureBox2->BackColor = System::Drawing::Color::Black;
			this->pictureBox2->BorderStyle = System::Windows::Forms::BorderStyle::Fixed3D;
			this->pictureBox2->Location = System::Drawing::Point(422, 70);
			this->pictureBox2->Name = L"pictureBox2";
			this->pictureBox2->Size = System::Drawing::Size(250, 175);
			this->pictureBox2->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->pictureBox2->TabIndex = 5;
			this->pictureBox2->TabStop = false;
			// 
			// button2
			// 
			this->button2->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"button2.BackgroundImage")));
			this->button2->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->button2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 18, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->button2->Location = System::Drawing::Point(401, 310);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(100, 90);
			this->button2->TabIndex = 6;
			this->button2->UseVisualStyleBackColor = true;
			this->button2->Click += gcnew System::EventHandler(this, &Form1::button2_Click);
			// 
			// listView1
			// 
			this->listView1->Alignment = System::Windows::Forms::ListViewAlignment::Left;
			this->listView1->Columns->AddRange(gcnew cli::array< System::Windows::Forms::ColumnHeader^  >(1) { this->Classe });
			this->listView1->Font = (gcnew System::Drawing::Font(L"OpenSymbol", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->listView1->Items->AddRange(gcnew cli::array< System::Windows::Forms::ListViewItem^  >(10) {
				listViewItem1, listViewItem2,
					listViewItem3, listViewItem4, listViewItem5, listViewItem6, listViewItem7, listViewItem8, listViewItem9, listViewItem10
			});
			this->listView1->Location = System::Drawing::Point(507, 310);
			this->listView1->Name = L"listView1";
			this->listView1->Size = System::Drawing::Size(184, 196);
			this->listView1->TabIndex = 7;
			this->listView1->UseCompatibleStateImageBehavior = false;
			this->listView1->View = System::Windows::Forms::View::List;
			this->listView1->SelectedIndexChanged += gcnew System::EventHandler(this, &Form1::listView1_SelectedIndexChanged);
			// 
			// Classe
			// 
			this->Classe->Width = 200;
			// 
			// textBox2
			// 
			this->textBox2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 21.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->textBox2->Location = System::Drawing::Point(401, 466);
			this->textBox2->Multiline = true;
			this->textBox2->Name = L"textBox2";
			this->textBox2->Size = System::Drawing::Size(100, 40);
			this->textBox2->TabIndex = 8;
			this->textBox2->Text = L"20";
			this->textBox2->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label1->Location = System::Drawing::Point(25, 44);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(184, 20);
			this->label1->TabIndex = 9;
			this->label1->Text = L"-CAMERA CAPTURE-";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label2->Location = System::Drawing::Point(441, 44);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(212, 20);
			this->label2->TabIndex = 10;
			this->label2->Text = L"-MOUTH RECOGNITION-";
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label3->Location = System::Drawing::Point(441, 287);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(172, 20);
			this->label3->TabIndex = 11;
			this->label3->Text = L"-OBTAIN-VISEMES-";
			// 
			// buttonSU
			// 
			this->buttonSU->Location = System::Drawing::Point(401, 407);
			this->buttonSU->Name = L"buttonSU";
			this->buttonSU->Size = System::Drawing::Size(100, 23);
			this->buttonSU->TabIndex = 12;
			this->buttonSU->Text = L"buttonSU";
			this->buttonSU->UseVisualStyleBackColor = true;
			this->buttonSU->Click += gcnew System::EventHandler(this, &Form1::buttonSU_Click);
			// 
			// buttonGIU
			// 
			this->buttonGIU->Location = System::Drawing::Point(401, 437);
			this->buttonGIU->Name = L"buttonGIU";
			this->buttonGIU->Size = System::Drawing::Size(100, 23);
			this->buttonGIU->TabIndex = 13;
			this->buttonGIU->Text = L"buttonGIU";
			this->buttonGIU->UseVisualStyleBackColor = true;
			this->buttonGIU->Click += gcnew System::EventHandler(this, &Form1::buttonGIU_Click);
			// 
			// Form1
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::Color::Gainsboro;
			this->ClientSize = System::Drawing::Size(703, 518);
			this->Controls->Add(this->buttonGIU);
			this->Controls->Add(this->buttonSU);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->textBox2);
			this->Controls->Add(this->listView1);
			this->Controls->Add(this->button2);
			this->Controls->Add(this->pictureBox2);
			this->Controls->Add(this->textBox1);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->pictureBox1);
			this->Controls->Add(this->menuStrip1);
			this->MainMenuStrip = this->menuStrip1;
			this->Name = L"Form1";
			this->Text = L"Form1";
			this->FormClosed += gcnew System::Windows::Forms::FormClosedEventHandler(this, &Form1::Form1_FormClosed);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->EndInit();
			this->menuStrip1->ResumeLayout(false);
			this->menuStrip1->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox2))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion

	private: System::Void button1_Click(System::Object^  sender, System::EventArgs^  e) {
		if (camera_on == false){
			//accendo pictureBox
			camera_on = true;
			button1->BackgroundImage = System::Drawing::Image::FromFile("button_red.png");
			button1->Text = L"OFF";
		    capture = cvCreateCameraCapture(CV_CAP_ANY);
		    if (capture) {
				timer1->Start();
			}
				 
		}
		else{
			//spengo pictureBox
			camera_on = false;
			button1->Text = L"ON";
			button1->BackgroundImage = System::Drawing::Image::FromFile("button_green.png");
			//immagine nera in picture box1
			pictureBox1->Image = gcnew    //replacement of cvShowImage
				System::Drawing::Bitmap(frame->width, frame->height, frame->widthStep,
				System::Drawing::Imaging::PixelFormat::Format24bppRgb, (System::IntPtr) NULL);
			pictureBox1->Refresh();
			//riabilito textBox2
			textBox2->Enabled = true; 
			cvReleaseCapture(&capture);
		}
		//num_visemi da salvare per ogni classe
		System::String^ string_text_box2 = textBox2->Text;
		num_item_per_class = System::Int32::Parse(string_text_box2);
		
	}

	private: System::Void button2_Click(System::Object^  sender, System::EventArgs^  e) {
		if (camera_on == true){
			if (inizia == false) {
				button2->BackgroundImage = System::Drawing::Image::FromFile("button2_red.png");
				textBox2->Enabled = false;
				inizia = true;
				//sndPlaySound("beep_yes", SND_ASYNC);

			}
			else {
				inizia = false;
				button2->BackgroundImage = System::Drawing::Image::FromFile("button2_green.png");
				//immagine nera in picture box1
				pictureBox2->Image = gcnew    //replacement of cvShowImage
					System::Drawing::Bitmap(frame->width, frame->height, frame->widthStep,
					System::Drawing::Imaging::PixelFormat::Format24bppRgb, (System::IntPtr) NULL);
				pictureBox2->Refresh();
			}
			textBox1->Text = textBox1->Text + "\r\n" + inizia;
			textBox1->SelectionStart = textBox1->Text->Length;
			textBox1->ScrollToCaret();
		}
		
	}



	private: System::Void timer1_Tick(System::Object^  sender, System::EventArgs^  e) {
		string imagename;
		fino_a = num_item_per_class * (regola_index + 1);
		textBox1->Text = textBox1->Text + "\r\n FINO_A :" + fino_a;
		textBox1->SelectionStart = textBox1->Text->Length;
		textBox1->ScrollToCaret();

		

		//textBox1->Text = textBox1->Text + "\r\n" + num_item_per_class;
		//textBox1->SelectionStart = textBox1->Text->Length;
		//textBox1->ScrollToCaret();
		//Coloro corrispondente scritta visema 

		System::String^ item_list_viseme = listView1->Items[regola_index]->Text;
		listView1->Items[regola_index]->BackColor = System::Drawing::Color::Green;

		//e lo scrivo nella textBox
		//textBox1->Text = textBox1->Text + "\r\n" + item_list_viseme;
		//textBox1->SelectionStart = textBox1->Text->Length;
		//textBox1->ScrollToCaret();

		framenumber += 1;
		//textBox1->Text = textBox1->Text + "\r\n" + framenumber;
		//textBox1->SelectionStart = textBox1->Text->Length;
		//textBox1->ScrollToCaret();
		frame = cvQueryFrame(capture);

		if (frame != NULL){
			if (inizia == true)
			{
				if (conta <= fino_a)
				{
				
				
				CvSize s = cvGetSize(frame);
				int d = frame->depth;
				int c = frame->nChannels;
				mouthRegion = cvCreateImage(s, d, c); // (s, 8, 3)
				croppedRectangle = Rect(300, 300, 100, 100); //coordinate crop + width,height crop 
				result = cvCreateImage(s, d, c); // (s, 8, 3) 
				cvCopy(frame,frame); //it's important if u make the image in 3 channel or filtering
				Mat eccolo;
				try{
					eccolo = findLip(frame, faceDetector, mouthRegion, mouthFound);
				}
				catch (cv::Exception &e){ cout << e.what() << endl; }

				//textBox1->Text = textBox1->Text + "\r\n MOUTH_FOUND :" + mouthFound;
				//textBox1->SelectionStart = textBox1->Text->Length;
				//textBox1->ScrollToCaret();

				myMat = mouthRegion;
				croppedRectangle = Rect(300, 300, 100, 100); //coordinate crop + width,height crop 
				croppedImage = myMat(croppedRectangle);

				//se findLip ha trovato qualcosa
				if (!eccolo.empty())
				{
				IplImage prova = eccolo;
				IplImage* somePointer = &prova;

				imagename = "";

				//if (framenumber % 10 == 0)
				//{
					
					
					//scrivo stringa per immagine
					imagename = "images/image" + inttostr(photocount) + ".JPEG";
					f << imagename << " " << regola_index << endl;
					//converto string in System::String per poterlo stampare su TextBox
					System::String^ string = gcnew System::String(imagename.c_str()); 
					// e la stampo su textBox
					//textBox1->Text = textBox1->Text + "\r\n" + string;
					//textBox1->SelectionStart = textBox1->Text->Length;
					//textBox1->ScrollToCaret();

					//questo serve per poter salvare l'immagine 
					vector<int> compression_params;
					//vector that stores the compression parameters of the image
					compression_params.push_back(CV_IMWRITE_JPEG_QUALITY);
					//specify the compression technique
					compression_params.push_back(100); //specify the compression quality
					
					//incremento photocount per contarore immagini salvate
					photocount++;

					//salvo l'immagine
					imwrite(imagename, eccolo, compression_params);

					//la mostro nella pictureBox2
					pictureBox2->Image = gcnew    //replacement of cvShowImage
						System::Drawing::Bitmap(somePointer->width, somePointer->height, somePointer->widthStep,
						System::Drawing::Imaging::PixelFormat::Format24bppRgb, (System::IntPtr) somePointer->imageData);
					pictureBox2->Refresh();

					conta++;

					textBox1->Text = textBox1->Text + "\r\nCONTA= " + conta;
					textBox1->SelectionStart = textBox1->Text->Length;
					textBox1->ScrollToCaret();
				}

				}
			}
			else
			{
				
				inizia = false;
				button2->BackgroundImage = System::Drawing::Image::FromFile("button2_green.png");
				//immagine nera in picture box1
				pictureBox2->Image = gcnew    //replacement of cvShowImage
					System::Drawing::Bitmap(frame->width, frame->height, frame->widthStep,
					System::Drawing::Imaging::PixelFormat::Format24bppRgb, (System::IntPtr) NULL);
				pictureBox2->Refresh();
			}

			
			pictureBox1->Image  = gcnew    //replacement of cvShowImage
			System::Drawing::Bitmap(frame->width,frame->height,frame->widthStep,
			System::Drawing::Imaging::PixelFormat::Format24bppRgb,(System::IntPtr) frame->imageData);
			pictureBox1->Refresh();

			
		}
	}

	private: System::Void exitToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
				 cvReleaseCapture(&capture);
				 createSynsetWord();
				 Application::Exit();
			 }

	private: System::Void Form1_FormClosed(System::Object^  sender, System::Windows::Forms::FormClosedEventArgs^  e) {
				cvReleaseCapture(&capture);
				createSynsetWord();
				Application::Exit();
	}

    
private: System::Void listView1_SelectedIndexChanged(System::Object^  sender, System::EventArgs^  e) {

}


private: System::Void buttonSU_Click(System::Object^  sender, System::EventArgs^  e) {
	if (regola_index >= 0){
		System::String^ item_list_viseme = listView1->Items[regola_index]->Text;
		listView1->Items[regola_index]->BackColor = System::Drawing::Color::White;
		if (N_MIN >= 0 && N_MIN <= NUM_CLASSI){
			if(regola_index > 0) regola_index--;
			System::String^ item_list_viseme = listView1->Items[regola_index]->Text;
			listView1->Items[regola_index]->BackColor = System::Drawing::Color::Yellow;
			textBox1->Text = textBox1->Text + "\r\n" + regola_index;
			textBox1->SelectionStart = textBox1->Text->Length;
			textBox1->ScrollToCaret();
		}

	}
			
}
private: System::Void buttonGIU_Click(System::Object^  sender, System::EventArgs^  e) {
	if (regola_index >= 0){
		System::String^ item_list_viseme = listView1->Items[regola_index]->Text;
		listView1->Items[regola_index]->BackColor = System::Drawing::Color::White;
		if (N_MIN >= 0 && N_MIN <= NUM_CLASSI){
			if (regola_index < 9) regola_index++;
			System::String^ item_list_viseme = listView1->Items[regola_index]->Text;
			listView1->Items[regola_index]->BackColor = System::Drawing::Color::Yellow;	
			textBox1->Text = textBox1->Text + "\r\n" + regola_index;
			textBox1->SelectionStart = textBox1->Text->Length;
		    textBox1->ScrollToCaret();
		}
	}
}
};

}

string inttostr(int input)
{
	stringstream ss;
	ss << input;
	return ss.str();
}

//restituisce lo std output di un comando eseguito da terminale sottoforma di stringa
string GetStdoutFromCommand(string cmd) {

	string data;
	FILE * stream;
	const int max_buffer = 256;
	char buffer[max_buffer];
	cmd.append(" 2>&1");

	stream = _popen(cmd.c_str(), "r");
	if (stream) {
		while (!feof(stream))
			if (fgets(buffer, max_buffer, stream) != NULL) data.append(buffer);
		_pclose(stream);
	}
	return data;
}

//rimuove carattere x data una stringa y
string RemoveChar(string str, char c)
{
	string result;
	for (size_t i = 0; i < str.size(); i++)
	{
		char currentChar = str[i];
		if (currentChar != c)
			result += currentChar;
	}
	return result;
}

void createSynsetWord(){
	fstream f2("synset_word.txt", ios::out); //apre il file in scrittura (cancellando quello che già c'era
	for (int i = 0; i <= NUM_CLASSI; i++){
		cout << i << " " << "viseme" << i << endl;
		f2 << i << " " << "viseme" << i << endl;
	}

}

