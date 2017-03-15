#pragma once
#include "stdafx.h"
#include "ImageProcess.hpp"
#include <fstream>
#include <iostream>
#include <string>
#include <fstream>
#include <stdio.h> 
#include <stdlib.h>
#include <string>
#include <direct.h>
#include "Form_info.h"

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
bool copyFile(const char *SRC, const char* DEST);
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
//initialize image counter
int photocount = 1; 

int N_MIN = 0;
int regola_index = 0; // per stabilire tramite pulsanti quale classe classificare
int NUM_CLASSI = 9;

fstream f1("train.txt", ios::out); //apre il file in scrittura (cancellando quello che già c'era)
//fstream f1_1("C:\\Projects\\prova\\caffe\\data\\viseme_prova\\train.txt", ios::out); 
//fstream f1_2("C:\\Projects\\prova\\caffe\\data\\viseme_prova\\val.txt", ios::out);

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
	private: System::Windows::Forms::Button^  button1;

	protected:

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

	private: System::Windows::Forms::Button^  buttonGIU;
	private: System::Windows::Forms::TextBox^  textBoxViseme;
	private: System::Windows::Forms::Button^  buttonCreateImagenet;
	private: System::Windows::Forms::Label^  label4;
	private: System::Windows::Forms::Label^  label5;
	private: System::Windows::Forms::Button^  buttonImagenet_mean;
	private: System::Windows::Forms::Label^  label6;
	private: System::Windows::Forms::Button^  buttonStartTrain;





	private: System::Windows::Forms::TextBox^  textBoxControlCreateImagenetTrain;

	private: System::Windows::Forms::TextBox^  textBoxStdOut;

	private: System::Windows::Forms::Label^  label8;
	private: System::Windows::Forms::Label^  label9;
	private: System::Windows::Forms::TextBox^  textBoxControlCreateImagenetVal;
	private: System::Windows::Forms::TextBox^  textBoxControlmakeImagenetMean;
	private: System::Windows::Forms::TextBox^  textBoxControlStartTrain;
	private: System::Windows::Forms::ToolStripMenuItem^  informazioniToolStripMenuItem;




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
			this->informazioniToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
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
			this->buttonGIU = (gcnew System::Windows::Forms::Button());
			this->textBoxViseme = (gcnew System::Windows::Forms::TextBox());
			this->buttonCreateImagenet = (gcnew System::Windows::Forms::Button());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->buttonImagenet_mean = (gcnew System::Windows::Forms::Button());
			this->label6 = (gcnew System::Windows::Forms::Label());
			this->buttonStartTrain = (gcnew System::Windows::Forms::Button());
			this->textBoxControlCreateImagenetTrain = (gcnew System::Windows::Forms::TextBox());
			this->textBoxStdOut = (gcnew System::Windows::Forms::TextBox());
			this->label8 = (gcnew System::Windows::Forms::Label());
			this->label9 = (gcnew System::Windows::Forms::Label());
			this->textBoxControlCreateImagenetVal = (gcnew System::Windows::Forms::TextBox());
			this->textBoxControlmakeImagenetMean = (gcnew System::Windows::Forms::TextBox());
			this->textBoxControlStartTrain = (gcnew System::Windows::Forms::TextBox());
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
			this->button1->Location = System::Drawing::Point(362, 70);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(78, 78);
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
			this->menuStrip1->Size = System::Drawing::Size(959, 24);
			this->menuStrip1->TabIndex = 3;
			this->menuStrip1->Text = L"menuStrip1";
			// 
			// fileToolStripMenuItem
			// 
			this->fileToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(2) {
				this->informazioniToolStripMenuItem,
					this->exitToolStripMenuItem
			});
			this->fileToolStripMenuItem->Name = L"fileToolStripMenuItem";
			this->fileToolStripMenuItem->Size = System::Drawing::Size(37, 20);
			this->fileToolStripMenuItem->Text = L"File";
			// 
			// informazioniToolStripMenuItem
			// 
			this->informazioniToolStripMenuItem->Name = L"informazioniToolStripMenuItem";
			this->informazioniToolStripMenuItem->Size = System::Drawing::Size(141, 22);
			this->informazioniToolStripMenuItem->Text = L"Informazioni";
			this->informazioniToolStripMenuItem->Click += gcnew System::EventHandler(this, &Form1::informazioniToolStripMenuItem_Click);
			// 
			// exitToolStripMenuItem
			// 
			this->exitToolStripMenuItem->Name = L"exitToolStripMenuItem";
			this->exitToolStripMenuItem->Size = System::Drawing::Size(141, 22);
			this->exitToolStripMenuItem->Text = L"Exit";
			this->exitToolStripMenuItem->Click += gcnew System::EventHandler(this, &Form1::exitToolStripMenuItem_Click);
			// 
			// textBox1
			// 
			this->textBox1->Location = System::Drawing::Point(12, 316);
			this->textBox1->Multiline = true;
			this->textBox1->Name = L"textBox1";
			this->textBox1->ScrollBars = System::Windows::Forms::ScrollBars::Vertical;
			this->textBox1->Size = System::Drawing::Size(320, 223);
			this->textBox1->TabIndex = 4;
			// 
			// pictureBox2
			// 
			this->pictureBox2->BackColor = System::Drawing::Color::Black;
			this->pictureBox2->BorderStyle = System::Windows::Forms::BorderStyle::Fixed3D;
			this->pictureBox2->Location = System::Drawing::Point(465, 70);
			this->pictureBox2->Name = L"pictureBox2";
			this->pictureBox2->Size = System::Drawing::Size(200, 200);
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
			this->button2->Location = System::Drawing::Point(362, 258);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(78, 78);
			this->button2->TabIndex = 6;
			this->button2->UseVisualStyleBackColor = true;
			this->button2->Click += gcnew System::EventHandler(this, &Form1::button2_Click);
			// 
			// listView1
			// 
			this->listView1->Alignment = System::Windows::Forms::ListViewAlignment::Left;
			this->listView1->Columns->AddRange(gcnew cli::array< System::Windows::Forms::ColumnHeader^  >(1) { this->Classe });
			this->listView1->Font = (gcnew System::Drawing::Font(L"OpenSymbol", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->listView1->Items->AddRange(gcnew cli::array< System::Windows::Forms::ListViewItem^  >(10) {
				listViewItem1, listViewItem2,
					listViewItem3, listViewItem4, listViewItem5, listViewItem6, listViewItem7, listViewItem8, listViewItem9, listViewItem10
			});
			this->listView1->Location = System::Drawing::Point(465, 307);
			this->listView1->Name = L"listView1";
			this->listView1->Size = System::Drawing::Size(200, 161);
			this->listView1->TabIndex = 7;
			this->listView1->UseCompatibleStateImageBehavior = false;
			this->listView1->View = System::Windows::Forms::View::List;
			this->listView1->SelectedIndexChanged += gcnew System::EventHandler(this, &Form1::listView1_SelectedIndexChanged);
			// 
			// Classe
			// 
			this->Classe->Width = 400;
			// 
			// textBox2
			// 
			this->textBox2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 21.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->textBox2->Location = System::Drawing::Point(350, 426);
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
			this->label2->Location = System::Drawing::Point(461, 44);
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
			this->label3->Location = System::Drawing::Point(474, 281);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(172, 20);
			this->label3->TabIndex = 11;
			this->label3->Text = L"-OBTAIN-VISEMES-";
			// 
			// buttonGIU
			// 
			this->buttonGIU->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"buttonGIU.BackgroundImage")));
			this->buttonGIU->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->buttonGIU->Location = System::Drawing::Point(362, 342);
			this->buttonGIU->Name = L"buttonGIU";
			this->buttonGIU->Size = System::Drawing::Size(78, 78);
			this->buttonGIU->TabIndex = 13;
			this->buttonGIU->UseVisualStyleBackColor = true;
			this->buttonGIU->Click += gcnew System::EventHandler(this, &Form1::buttonGIU_Click);
			// 
			// textBoxViseme
			// 
			this->textBoxViseme->BackColor = System::Drawing::Color::White;
			this->textBoxViseme->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 21.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->textBoxViseme->Location = System::Drawing::Point(350, 495);
			this->textBoxViseme->Multiline = true;
			this->textBoxViseme->Name = L"textBoxViseme";
			this->textBoxViseme->Size = System::Drawing::Size(315, 40);
			this->textBoxViseme->TabIndex = 14;
			this->textBoxViseme->Text = L"A,L,N,NE,VA,CA";
			this->textBoxViseme->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			// 
			// buttonCreateImagenet
			// 
			this->buttonCreateImagenet->Font = (gcnew System::Drawing::Font(L"Courier New", 9.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->buttonCreateImagenet->Location = System::Drawing::Point(693, 82);
			this->buttonCreateImagenet->Name = L"buttonCreateImagenet";
			this->buttonCreateImagenet->Size = System::Drawing::Size(168, 56);
			this->buttonCreateImagenet->TabIndex = 15;
			this->buttonCreateImagenet->Text = L"create_imagenet.sh";
			this->buttonCreateImagenet->UseVisualStyleBackColor = true;
			this->buttonCreateImagenet->Click += gcnew System::EventHandler(this, &Form1::buttonCreateImagenet_Click);
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 11.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label4->Location = System::Drawing::Point(686, 61);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(257, 18);
			this->label4->TabIndex = 16;
			this->label4->Text = L"1. Convert DATASET to LMDB format";
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 11.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label5->Location = System::Drawing::Point(690, 162);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(160, 18);
			this->label5->TabIndex = 18;
			this->label5->Text = L"2. Calcola Medie canali";
			// 
			// buttonImagenet_mean
			// 
			this->buttonImagenet_mean->Font = (gcnew System::Drawing::Font(L"Courier New", 9.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->buttonImagenet_mean->Location = System::Drawing::Point(689, 183);
			this->buttonImagenet_mean->Name = L"buttonImagenet_mean";
			this->buttonImagenet_mean->Size = System::Drawing::Size(218, 42);
			this->buttonImagenet_mean->TabIndex = 17;
			this->buttonImagenet_mean->Text = L"make_imagenet_mean.sh ";
			this->buttonImagenet_mean->UseVisualStyleBackColor = true;
			this->buttonImagenet_mean->Click += gcnew System::EventHandler(this, &Form1::buttonImagenet_mean_Click);
			// 
			// label6
			// 
			this->label6->AutoSize = true;
			this->label6->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 11.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label6->Location = System::Drawing::Point(684, 246);
			this->label6->Name = L"label6";
			this->label6->Size = System::Drawing::Size(102, 18);
			this->label6->TabIndex = 20;
			this->label6->Text = L"3. Start TRAIN";
			// 
			// buttonStartTrain
			// 
			this->buttonStartTrain->Font = (gcnew System::Drawing::Font(L"Courier New", 11.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->buttonStartTrain->Location = System::Drawing::Point(689, 267);
			this->buttonStartTrain->Name = L"buttonStartTrain";
			this->buttonStartTrain->Size = System::Drawing::Size(218, 42);
			this->buttonStartTrain->TabIndex = 19;
			this->buttonStartTrain->Text = L"START_TRAIN";
			this->buttonStartTrain->UseVisualStyleBackColor = true;
			this->buttonStartTrain->Click += gcnew System::EventHandler(this, &Form1::buttonStartTrain_Click);
			// 
			// textBoxControlCreateImagenetTrain
			// 
			this->textBoxControlCreateImagenetTrain->BackColor = System::Drawing::Color::Red;
			this->textBoxControlCreateImagenetTrain->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 21.75F, System::Drawing::FontStyle::Bold,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->textBoxControlCreateImagenetTrain->Location = System::Drawing::Point(913, 82);
			this->textBoxControlCreateImagenetTrain->Multiline = true;
			this->textBoxControlCreateImagenetTrain->Name = L"textBoxControlCreateImagenetTrain";
			this->textBoxControlCreateImagenetTrain->Size = System::Drawing::Size(25, 27);
			this->textBoxControlCreateImagenetTrain->TabIndex = 25;
			this->textBoxControlCreateImagenetTrain->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			// 
			// textBoxStdOut
			// 
			this->textBoxStdOut->Location = System::Drawing::Point(687, 316);
			this->textBoxStdOut->Multiline = true;
			this->textBoxStdOut->Name = L"textBoxStdOut";
			this->textBoxStdOut->ScrollBars = System::Windows::Forms::ScrollBars::Vertical;
			this->textBoxStdOut->Size = System::Drawing::Size(257, 219);
			this->textBoxStdOut->TabIndex = 26;
			// 
			// label8
			// 
			this->label8->AutoSize = true;
			this->label8->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 11.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label8->Location = System::Drawing::Point(867, 88);
			this->label8->Name = L"label8";
			this->label8->Size = System::Drawing::Size(46, 18);
			this->label8->TabIndex = 28;
			this->label8->Text = L"Train-";
			// 
			// label9
			// 
			this->label9->AutoSize = true;
			this->label9->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 11.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label9->Location = System::Drawing::Point(874, 120);
			this->label9->Name = L"label9";
			this->label9->Size = System::Drawing::Size(33, 18);
			this->label9->TabIndex = 29;
			this->label9->Text = L"Val-";
			// 
			// textBoxControlCreateImagenetVal
			// 
			this->textBoxControlCreateImagenetVal->BackColor = System::Drawing::Color::Red;
			this->textBoxControlCreateImagenetVal->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 21.75F, System::Drawing::FontStyle::Bold,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->textBoxControlCreateImagenetVal->Location = System::Drawing::Point(913, 115);
			this->textBoxControlCreateImagenetVal->Multiline = true;
			this->textBoxControlCreateImagenetVal->Name = L"textBoxControlCreateImagenetVal";
			this->textBoxControlCreateImagenetVal->Size = System::Drawing::Size(25, 27);
			this->textBoxControlCreateImagenetVal->TabIndex = 30;
			this->textBoxControlCreateImagenetVal->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			// 
			// textBoxControlmakeImagenetMean
			// 
			this->textBoxControlmakeImagenetMean->BackColor = System::Drawing::Color::Red;
			this->textBoxControlmakeImagenetMean->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 21.75F, System::Drawing::FontStyle::Bold,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->textBoxControlmakeImagenetMean->Location = System::Drawing::Point(913, 185);
			this->textBoxControlmakeImagenetMean->Multiline = true;
			this->textBoxControlmakeImagenetMean->Name = L"textBoxControlmakeImagenetMean";
			this->textBoxControlmakeImagenetMean->Size = System::Drawing::Size(25, 40);
			this->textBoxControlmakeImagenetMean->TabIndex = 31;
			this->textBoxControlmakeImagenetMean->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			// 
			// textBoxControlStartTrain
			// 
			this->textBoxControlStartTrain->BackColor = System::Drawing::Color::Red;
			this->textBoxControlStartTrain->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 21.75F, System::Drawing::FontStyle::Bold,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->textBoxControlStartTrain->Location = System::Drawing::Point(913, 267);
			this->textBoxControlStartTrain->Multiline = true;
			this->textBoxControlStartTrain->Name = L"textBoxControlStartTrain";
			this->textBoxControlStartTrain->Size = System::Drawing::Size(25, 40);
			this->textBoxControlStartTrain->TabIndex = 32;
			this->textBoxControlStartTrain->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			// 
			// Form1
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::Color::Gainsboro;
			this->ClientSize = System::Drawing::Size(959, 547);
			this->Controls->Add(this->textBoxControlStartTrain);
			this->Controls->Add(this->textBoxControlmakeImagenetMean);
			this->Controls->Add(this->textBoxControlCreateImagenetVal);
			this->Controls->Add(this->label9);
			this->Controls->Add(this->label8);
			this->Controls->Add(this->textBoxStdOut);
			this->Controls->Add(this->textBoxControlCreateImagenetTrain);
			this->Controls->Add(this->label6);
			this->Controls->Add(this->buttonStartTrain);
			this->Controls->Add(this->label5);
			this->Controls->Add(this->buttonImagenet_mean);
			this->Controls->Add(this->label4);
			this->Controls->Add(this->buttonCreateImagenet);
			this->Controls->Add(this->textBoxViseme);
			this->Controls->Add(this->buttonGIU);
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

	System::String^ button_red = "C:\\Users\\Matteo\\Documents\\Visual Studio 2013\\Projects\\CreaDataset2\\Tutorial\\button_red.png";
	System::String^ button_green = "C:\\Users\\Matteo\\Documents\\Visual Studio 2013\\Projects\\CreaDataset2\\Tutorial\\button_green.png";
	System::String^ button2_red = "C:\\Users\\Matteo\\Documents\\Visual Studio 2013\\Projects\\CreaDataset2\\Tutorial\\button2_red.png";
	System::String^ button2_green = "C:\\Users\\Matteo\\Documents\\Visual Studio 2013\\Projects\\CreaDataset2\\Tutorial\\button2_green.png";

	//-----------------------------------------------------------------------------------
	//BOTTONE ACCENSIONE o SPEGNIMENTO CAMERA--------------------------------------------
	//-----------------------------------------------------------------------------------
	private: System::Void button1_Click(System::Object^  sender, System::EventArgs^  e) {
		//se camera è spenta
		if (camera_on == false){ 
			//accendo pictureBox
			camera_on = true;
			button1->BackgroundImage = System::Drawing::Image::FromFile(button_red); 
			button1->Text = L"OFF";
		    capture = cvCreateCameraCapture(CV_CAP_ANY);
		    if (capture) {
				timer1->Start(); //inizio la cattura dei frame (vedi timer1)
			} 
			//disabilito textBox2 per numero istanze classe
			textBox2->Enabled = true;
			textBox2->Enabled = false;
		}
		//se camera è accesa
		else{
			camera_on = false;
			button1->Text = L"ON";
			button1->BackgroundImage = System::Drawing::Image::FromFile(button_green);
			//immagine nera in picture box1
			pictureBox1->Image = gcnew    //replacement of cvShowImage
				System::Drawing::Bitmap(frame->width, frame->height, frame->widthStep,
				System::Drawing::Imaging::PixelFormat::Format24bppRgb, (System::IntPtr) NULL);
			pictureBox1->Refresh();
			//riabilito textBox2 per numero istanze classe
			textBox2->Enabled = true; 
			cvReleaseCapture(&capture);
		}	
	}
	//-----------------------------------------------------------------------------------	 
	//-----------------------------------------------------------------------------------
	//BOTTONE CATTURA VISEMI-------------------------------------------------------------
	//-----------------------------------------------------------------------------------
	private: System::Void button2_Click(System::Object^  sender, System::EventArgs^  e) {
		if (camera_on == true){
			if (inizia == false) {
				button2->BackgroundImage = System::Drawing::Image::FromFile(button2_red);
				inizia = true;
				//sndPlaySound("beep_yes", SND_ASYNC);

			}
			else {
				inizia = false;
				button2->BackgroundImage = System::Drawing::Image::FromFile(button2_green);
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
	//-----------------------------------------------------------------------------------
	//-----------------------------------------------------------------------------------
	//QUANDO ATTIVO LA CAMERA------------------------------------------------------------
	//-----------------------------------------------------------------------------------
	private: System::Void timer1_Tick(System::Object^  sender, System::EventArgs^  e) {

		//numero visemi/istanze da salvare per ogni classe
		System::String^ string_text_box2 = textBox2->Text;
		num_item_per_class = System::Int32::Parse(string_text_box2);
		//numero iterazioni per classe
		fino_a = num_item_per_class * (regola_index + 1);

		textBox1->Text = textBox1->Text + "\r\n FINO_A :" + fino_a;
		textBox1->SelectionStart = textBox1->Text->Length;
		textBox1->ScrollToCaret();

		//variabile per nome immagine da salvare
		string imagename;

		//coloro anche listina visemi
		System::String^ item_list_viseme = listView1->Items[regola_index]->Text;
		listView1->Items[regola_index]->BackColor = System::Drawing::Color::Yellow;

		//framenumber viene incrementato sempre a + 1 per fare un controllo sui frame da apprendere
		framenumber += 1;
		//textBox1->Text = textBox1->Text + "\r\n" + framenumber;
		//textBox1->SelectionStart = textBox1->Text->Length;
		//textBox1->ScrollToCaret();

		//catturo frame
		frame = cvQueryFrame(capture);
		//ruto di 180 sull'asse verticale l'immagine
		cvFlip(frame, frame, 180);

		if (frame != NULL)
		{
			//se premo pulsante cattura visemi (quello sopra alla freccia)
			if (inizia == true)
			{
				//coloro textBox che rappresenta visema da pronunciare di Verde
				this->textBoxViseme->BackColor = System::Drawing::Color::Green;

				System::String^ item_list_viseme = listView1->Items[regola_index]->Text;
				listView1->Items[regola_index]->BackColor = System::Drawing::Color::Green;

				if (conta < fino_a)
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

						//salvo ogni X frame
						//if (framenumber % 10 == 0)
						//{
						//scrivo stringa per immagine
						imagename = "image" + inttostr(photocount) + ".JPEG";
						f1 << imagename << " " << regola_index << endl;
						//f1_1 << imagename << " " << regola_index << endl;
						//f1_2 << imagename << " " << regola_index << endl;

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
						imwrite("images/"+imagename, eccolo, compression_params);
						imwrite("C:\\Projects\\prova\\caffe\\data\\viseme_prova\\train\\" + imagename, eccolo, compression_params);
						imwrite("C:\\Projects\\prova\\caffe\\data\\viseme_prova\\val\\" + imagename, eccolo, compression_params);


						//la mostro nella pictureBox2
						pictureBox2->Image = gcnew    //replacement of cvShowImage
							System::Drawing::Bitmap(somePointer->width, somePointer->height, somePointer->widthStep,
							System::Drawing::Imaging::PixelFormat::Format24bppRgb, (System::IntPtr) somePointer->imageData);
						pictureBox2->Refresh();

						conta++;

						textBox1->Text = textBox1->Text + "\r\n-----------------CONTA= " + conta;
						textBox1->SelectionStart = textBox1->Text->Length;
						textBox1->ScrollToCaret();
					}
				}
				else
				{
					this->textBoxViseme->BackColor = System::Drawing::Color::Yellow;
				}
			}
		else
		{
				
			inizia = false;
			button2->BackgroundImage = System::Drawing::Image::FromFile(button2_green);
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


private: System::Void buttonGIU_Click(System::Object^  sender, System::EventArgs^  e) {
	if (regola_index >= 0){
		System::String^ item_list_viseme = listView1->Items[regola_index]->Text;
		listView1->Items[regola_index]->BackColor = System::Drawing::Color::White;
		System::String^ stringa_visema;
		if (N_MIN >= 0 && N_MIN <= NUM_CLASSI && regola_index < 9)
		{
			regola_index++;
			//System::String^ item_list_viseme = listView1->Items[regola_index]->Text;
			if (regola_index == 0)
				stringa_visema = "A,L,N,NE,VA,CA,CHE";
			if (regola_index == 1)
				stringa_visema = "E,CA,GA,CHE,F,FI";
			if (regola_index == 2)
				stringa_visema = "I, CHI, BI, R, S, T, D, GR, Z";
			if (regola_index == 3)
				stringa_visema = "O,GO,CO,DO,PO,TO,RO";
			if (regola_index == 4)
				stringa_visema = "U,QU,GU,TU,SU,LU";
			if (regola_index == 5)
				stringa_visema = "F,V";
			if (regola_index == 6)
				stringa_visema = "T,D,Z,S,R";
			if (regola_index == 7)
				stringa_visema = "P,M,B";
			if (regola_index == 8)
				stringa_visema = "CI,GI,CE,GE,SH";
			if (regola_index == 9)
				stringa_visema = "NEUT (bocca chiusa)";


			textBoxViseme->Text = stringa_visema;
			listView1->Items[regola_index]->BackColor = System::Drawing::Color::Yellow;	
			textBox1->Text = textBox1->Text + "\r\n" + regola_index;
			textBox1->SelectionStart = textBox1->Text->Length;
		    textBox1->ScrollToCaret();
		}
		else
		{
			regola_index = 0;
			stringa_visema = "A,L,N,NE,VA,CA,CHE";
			textBoxViseme->Text = stringa_visema;
			System::String^ item_list_viseme = listView1->Items[0]->Text;
			listView1->Items[regola_index]->BackColor = System::Drawing::Color::Yellow;
			textBox1->Text = textBox1->Text + "\r\n" + regola_index;
			textBox1->SelectionStart = textBox1->Text->Length;
			textBox1->ScrollToCaret();
			
		}
	}
}

private: System::Void buttonCreateImagenet_Click(System::Object^  sender, System::EventArgs^  e) {
	
	//elimino file qualora fossero presenti
	GetStdoutFromCommand("rmdir /s /q C:\\Projects\\prova\\caffe\\examples\\viseme_prova\\train_lmdb");
	GetStdoutFromCommand("rmdir /s /q C:\\Projects\\prova\\caffe\\examples\\viseme_prova\\val_lmdb");
	//------------------------------------------------
	chdir("C:/Projects/prova/caffe");
	//------------------------------------------------
	//------------------------------------------------
	textBoxStdOut->Text = textBoxStdOut->Text + "TRAIN_LMDB: ";
	textBoxStdOut->SelectionStart = textBoxStdOut->Text->Length;
	textBoxStdOut->ScrollToCaret();
	string result_train = GetStdoutFromCommand("build\\tools\\Release\\convert_imageset.exe data\\viseme_prova\\train\\ data\\viseme_prova\\train.txt examples\\viseme_prova\\train_lmdb\\");
	System::String^ string_train = gcnew System::String(result_train.c_str());
	textBoxStdOut->Text = textBoxStdOut->Text + string_train;
	textBoxStdOut->SelectionStart = textBoxStdOut->Text->Length;
	textBoxStdOut->ScrollToCaret();
	this->textBoxControlCreateImagenetTrain->BackColor = System::Drawing::Color::Green;

	textBoxStdOut->Text = textBoxStdOut->Text + "VAL_LMDB: ";
	textBoxStdOut->SelectionStart = textBoxStdOut->Text->Length;
	textBoxStdOut->ScrollToCaret();
	string result_val = GetStdoutFromCommand("build\\tools\\Release\\convert_imageset.exe data\\viseme_prova\\val\\ data\\viseme_prova\\val.txt examples\\viseme_prova\\val_lmdb");
	System::String^ string_val = gcnew System::String(result_val.c_str());
	textBoxStdOut->Text = textBoxStdOut->Text + string_val;
	textBoxStdOut->SelectionStart = textBoxStdOut->Text->Length;
	textBoxStdOut->ScrollToCaret();
	this->textBoxControlCreateImagenetVal->BackColor = System::Drawing::Color::Green;
}

private: System::Void buttonImagenet_mean_Click(System::Object^  sender, System::EventArgs^  e) {

	chdir("C:/Projects/prova/caffe");
	textBoxStdOut->Text = textBoxStdOut->Text + "MAKE_IMAGENET_MEAN: ";
	textBoxStdOut->SelectionStart = textBoxStdOut->Text->Length;
	textBoxStdOut->ScrollToCaret();
	string result_make_imagenet_mean = GetStdoutFromCommand("build\\tools\\Release\\compute_image_mean.exe examples\\viseme_prova\\train_lmdb data\\viseme_prova\\imagenet_mean.binaryproto");
	System::String^ string_val = gcnew System::String(result_make_imagenet_mean.c_str());
	textBoxStdOut->Text = textBoxStdOut->Text + string_val;
	textBoxStdOut->SelectionStart = textBoxStdOut->Text->Length;
	textBoxStdOut->ScrollToCaret();
	this->textBoxControlmakeImagenetMean->BackColor = System::Drawing::Color::Green;

}
private: System::Void buttonStartTrain_Click(System::Object^  sender, System::EventArgs^  e) {

	chdir("C:/Projects/prova/caffe");
	textBoxStdOut->Text = textBoxStdOut->Text + "START TRAIN: ";
	textBoxStdOut->SelectionStart = textBoxStdOut->Text->Length;
	textBoxStdOut->ScrollToCaret();

	string result_make_imagenet_mean = GetStdoutFromCommand("build\\tools\\Release\\caffe.exe train --solver=examples\\viseme_prova\\solver.prototxt");
	System::String^ string_val = gcnew System::String(result_make_imagenet_mean.c_str());
	textBoxStdOut->Text = textBoxStdOut->Text + string_val;
	textBoxStdOut->SelectionStart = textBoxStdOut->Text->Length;
	textBoxStdOut->ScrollToCaret();
	this->textBoxControlmakeImagenetMean->BackColor = System::Drawing::Color::Green;
	textBoxStdOut->Text = textBoxStdOut->Text + "END TRAIN: ";
	textBoxStdOut->SelectionStart = textBoxStdOut->Text->Length;
	textBoxStdOut->ScrollToCaret();

}
private: System::Void informazioniToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
	Form_info^ form_informazioni = gcnew Form_info();
	form_informazioni->ShowDialog();
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

// copy in binary mode
bool copyFile(const char *SRC, const char* DEST)
{
	std::ifstream src(SRC, std::ios::binary);
	std::ofstream dest(DEST, std::ios::binary);
	dest << src.rdbuf();
	return src && dest;
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
	fstream f2("synset_words.txt", ios::out); //apre il file in scrittura (cancellando quello che già c'era
	fstream f2_2("C:\\Projects\\prova\\caffe\\data\\viseme_prova\\synset_words.txt", ios::out);
	for (int i = 0; i <= NUM_CLASSI; i++){
		cout << i << " " << "viseme" << i << endl;
		f2 << i << " " << "viseme" << i << endl;
		f2_2 << i << " " << "viseme" << i << endl;
	}

}

