#pragma once
#include "Tree.h"
#include "math.h"
namespace task2 {
	int MaxLevel=10;
	int start_height = 40;
	bool check = true;
	int Current_Level;

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Сводка для MyForm
	/// </summary>
	public ref class MyForm : public System::Windows::Forms::Form
	{
	public:
		MyForm(void)
		{
			InitializeComponent();
			//
			//TODO: добавьте код конструктора
			//
		}

	protected:
		/// <summary>
		/// Освободить все используемые ресурсы.
		/// </summary>
		~MyForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::PictureBox^  pictureBox1;
	protected:
	private: System::Windows::Forms::PictureBox^  pictureBox2;
	private: System::Windows::Forms::TextBox^  textBox1;
	private: System::Windows::Forms::Label^  label1;
	private: System::Windows::Forms::Button^  button1;

	private:
		/// <summary>
		/// Обязательная переменная конструктора.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Требуемый метод для поддержки конструктора — не изменяйте 
		/// содержимое этого метода с помощью редактора кода.
		/// </summary>
		void InitializeComponent(void)
		{
			this->pictureBox1 = (gcnew System::Windows::Forms::PictureBox());
			this->pictureBox2 = (gcnew System::Windows::Forms::PictureBox());
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->button1 = (gcnew System::Windows::Forms::Button());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox2))->BeginInit();
			this->SuspendLayout();
			// 
			// pictureBox1
			// 
			this->pictureBox1->Location = System::Drawing::Point(30, 12);
			this->pictureBox1->Name = L"pictureBox1";
			this->pictureBox1->Size = System::Drawing::Size(308, 265);
			this->pictureBox1->TabIndex = 0;
			this->pictureBox1->TabStop = false;
			// 
			// pictureBox2
			// 
			this->pictureBox2->Location = System::Drawing::Point(338, 12);
			this->pictureBox2->Name = L"pictureBox2";
			this->pictureBox2->Size = System::Drawing::Size(330, 265);
			this->pictureBox2->TabIndex = 1;
			this->pictureBox2->TabStop = false;
			this->pictureBox2->MouseClick += gcnew System::Windows::Forms::MouseEventHandler(this, &MyForm::pictureBox2_MouseClick_1);
			// 
			// textBox1
			// 
			this->textBox1->Location = System::Drawing::Point(361, 292);
			this->textBox1->Name = L"textBox1";
			this->textBox1->Size = System::Drawing::Size(49, 20);
			this->textBox1->TabIndex = 2;
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(285, 295);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(70, 13);
			this->label1->TabIndex = 3;
			this->label1->Text = L"max уровень";
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(306, 316);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(75, 23);
			this->button1->TabIndex = 4;
			this->button1->Text = L"button1";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &MyForm::button1_Click);
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(724, 358);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->textBox1);
			this->Controls->Add(this->pictureBox2);
			this->Controls->Add(this->pictureBox1);
			this->Name = L"MyForm";
			this->Text = L"MyForm";
			this->Load += gcnew System::EventHandler(this, &MyForm::MyForm_Load);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox2))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
		private: void Paint_Clear()
		{
			Graphics^ Графика = pictureBox1->CreateGraphics();
			Graphics^ Графика2 = pictureBox2->CreateGraphics();
			Графика->Clear(Color::White);
			Графика2->Clear(Color::White);
		}

		private: void paint_clear_fract()
		{
			Graphics^ Графика = pictureBox1->CreateGraphics();
			
			Графика->Clear(Color::White);
	
		}
		private: Color choose_color(int Level)
		{
			switch (Level)
			{
			case 1: return Color::FromName("Black"); break;
			case 2:	return Color::FromName("DeepSkyBlue"); break;
			case 3: return Color::FromName("Cyan"); 	 break;
			case 4: return Color::FromName("BlueViolet"); break;
			case 5:	return Color::FromName("Violet"); break;
			case 6:	return Color::FromName("Red"); break;
			case 7:	return Color::FromName("Orange"); break;
			case 8:	return Color::FromName("Gold"); break;
			case 9:	return Color::FromName("Pink"); break;
			default: return Color::FromName("Green"); break;
			}
		}


		private: void draw_tree_leaf(Tree_Node ^tree, Graphics ^Grafica, Color ^SomeStrangeColor)
		{
			Color CurrentColor;
			CurrentColor = choose_color(tree->level);
			Brush^ Заливка = gcnew SolidBrush(CurrentColor);
			Grafica->FillEllipse(Заливка, tree->treeX - (7 - tree->level), tree->treeY - (7 - tree->level), 2 * (7 - tree->level), 2 * (7 - tree->level));
		}

		private: void draw_tree(Tree_Node ^tree, Graphics ^Grafica)
		{
			Color CurrentColor;
			CurrentColor = choose_color(tree->level);
			draw_tree_leaf(tree, Grafica, CurrentColor);
			if (tree->level != MaxLevel)
			{
				Pen^ brush = gcnew Pen(CurrentColor);
				Grafica->DrawLine(brush, tree->treeX, tree->treeY, tree->next_one->treeX, tree->next_one->treeY);
				draw_tree(tree->next_one, Grafica);
				Grafica->DrawLine(brush, tree->treeX, tree->treeY, tree->next_two->treeX, tree->next_two->treeY);
				draw_tree(tree->next_two, Grafica);
				Grafica->DrawLine(brush, tree->treeX, tree->treeY, tree->next_three->treeX, tree->next_three->treeY);
				draw_tree(tree->next_three, Grafica);
				Grafica->DrawLine(brush, tree->treeX, tree->treeY, tree->next_four->treeX, tree->next_four->treeY);
				draw_tree(tree->next_four, Grafica);

			}
		}
		private: void generate_tree(Tree_Node ^tree)
		{
			if (tree->level != MaxLevel)
			{
				Tree_Node ^p;
		

				int NewLevel = (tree->level + 1);

			
				p = gcnew Tree_Node(tree->x1, tree->y1,
					(2* tree->x1+ tree->x2)/3, ((2 * tree->y1 + tree->y2) / 3), tree->treeX - (3 * tree->treeX_dif), tree->treeY + start_height, (tree->treeX_dif / 4), NewLevel);
				tree->next_one = p;
				generate_tree(tree->next_one);
				p = gcnew Tree_Node((2 * tree->x1 + tree->x2) / 3, ((2 * tree->y1 + tree->y2) / 3),
					(( tree->x1 + tree->x2) / 2)+((tree->y1- tree->y2)/(2*sqrt(3.0))), ((tree->y1 + tree->y2) / 2) + ((tree->x2 - tree->x1) / (2 * sqrt(3.0))), 
					tree->treeX - (tree->treeX_dif), tree->treeY + start_height, (tree->treeX_dif / 4), NewLevel);
				tree->next_two = p;
				generate_tree(tree->next_two);
				p = gcnew Tree_Node(((tree->x1 + tree->x2) / 2) + ((tree->y1 - tree->y2) / (2 * sqrt(3.0))), ((tree->y1 + tree->y2) / 2) + ((tree->x2 - tree->x1) / (2 * sqrt(3.0))),
					(2 * tree->x2 + tree->x1) / 3, ((2 * tree->y2 + tree->y1) / 3),
					tree->treeX + (tree->treeX_dif), tree->treeY + start_height, (tree->treeX_dif / 4), NewLevel);
				tree->next_three = p;
				generate_tree(tree->next_three);
				p = gcnew Tree_Node(
					(2 * tree->x2 + tree->x1) / 3, ((2 * tree->y2 + tree->y1) / 3), tree->x2, tree->y2,
					tree->treeX + (3 * tree->treeX_dif), tree->treeY + start_height, (tree->treeX_dif / 4), NewLevel);
				tree->next_four = p;
				generate_tree(tree->next_four);
			}
		}

		//рисуем фрактал
		private: void draw_part_of_fractal(Tree_Node^ tree,  Point left, Point right, Graphics^ Графика, bool first)
		{
			Color CurrentColor;
			if (first)
				CurrentColor = choose_color(tree->level);
			else CurrentColor = choose_color(tree->level-1);

			Pen^ Brush;
			Brush = gcnew Pen(CurrentColor);
			array<Point>^ curvePoints;
			curvePoints = gcnew array<Point>(3);

			curvePoints[0] = right;
			curvePoints[1] = left;
			Графика->DrawLine(Brush, curvePoints[0], curvePoints[1]);

		}

	private: void paint_fractal(Tree_Node ^tree, Graphics^ Графика, bool first)
	{
		Point left = Point(tree->x2, tree->y2);
		Point right = Point(tree->x1, tree->y1);
		draw_part_of_fractal(tree, left, right, Графика,first);
		
		if (tree->level != MaxLevel)
		{
			paint_fractal(tree->next_one, Графика, false);
			paint_fractal(tree->next_two, Графика,true);
			paint_fractal(tree->next_three, Графика,true);
			paint_fractal(tree->next_four, Графика, false);
			Point left_white = Point(tree->next_two->x1, tree->next_two->y1);
			Point right_white = Point(tree->next_three->x2, tree->next_three->y2);
			Pen^ Brush;
			Brush = gcnew Pen(Color::White);
			Brush->Width = 3;
			Brush->DashStyle = System::Drawing::Drawing2D::DashStyle::Solid;
			
			Графика->DrawLine(Brush, left_white, right_white);
		
		}

	}
#pragma endregion
	void error(double a) {
		MessageBox::Show("Некорректное значение: " + a.ToString(), "Ошибка", MessageBoxButtons::OK, MessageBoxIcon::Exclamation);
	};
	private: System::Void MyForm_Load(System::Object^  sender, System::EventArgs^  e) {
	}
	private: System::Void button1_Click(System::Object^  sender, System::EventArgs^  e) {
		Paint_Clear();
		MaxLevel = Convert::ToInt32(textBox1->Text);//Число уровней фрактала
		if (MaxLevel < 1) { error(MaxLevel); MaxLevel = 1; }
		if (MaxLevel > 8) { error(MaxLevel); MaxLevel = 8; }
		float X1, Y1, X2, Y2, X3, Y3;
		X1 = 50;
		Y1 = 200;
		X2 = 200;
		Y2 = 200;

		Current_Level = MaxLevel;
		Y3 = (Y2 + Y1) / 2 + (X1-X2)*sqrt(3.0) / 2;
		X3 = (X2 + X1) / 2 + (Y2 - Y1)*sqrt(3.0) / 2;
		Tree_Node ^side1, ^side2, ^side3;
		side1 = gcnew Tree_Node(X1, Y1,X2,Y2, (pictureBox2->Width / 2), (start_height / 2), (pictureBox2->Height / 7),1);
		generate_tree(side1);

		side2 = gcnew Tree_Node(X3, Y3, X1, Y1, (pictureBox2->Width / 2), (start_height / 2), (pictureBox2->Height / 7), 1);
		generate_tree(side2);

		side3 = gcnew Tree_Node(X2, Y2,X3, Y3,  (pictureBox2->Width / 2), (start_height / 2), (pictureBox2->Height / 7), 1);
		generate_tree(side3);
		Bitmap ^Tree_bitmab = gcnew Bitmap(pictureBox2->Width, pictureBox2->Height);
		Graphics^ GraphikaBitmap = Graphics::FromImage(Tree_bitmab);
		GraphikaBitmap->Clear(Color::White);
		draw_tree(side1, GraphikaBitmap);
		draw_tree(side2, GraphikaBitmap);
		draw_tree(side3, GraphikaBitmap);
		pictureBox2->Image = Tree_bitmab;

		Graphics^ Графика2 = pictureBox1->CreateGraphics();
		paint_fractal(side1, Графика2, true);
		paint_fractal(side2, Графика2, true);
		paint_fractal(side3, Графика2, true);

	}

private: System::Void pictureBox2_MouseClick_1(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e) {
	Point p_mouse = Point(e->X, e->Y);
	int click_y = p_mouse.Y;

	switch (Current_Level)
	{
	case 1:
		if ((click_y >= 0) && (click_y <= 40)) MaxLevel = 1;
		break;
	case 2:
		if ((click_y >= 0) && (click_y <= 40)) MaxLevel = 1;
		if ((click_y >= 41) && (click_y <= 80)) MaxLevel = 2;
		break;
	case 3:
		if ((click_y >= 0) && (click_y <= 40)) MaxLevel = 1;
		if ((click_y >= 41) && (click_y <= 80)) MaxLevel = 2;
		if ((click_y >= 81) && (click_y <= 120)) MaxLevel = 3;
		break;
	case 4:
		if ((click_y >= 0) && (click_y <= 40)) MaxLevel = 1;
		if ((click_y >= 41) && (click_y <= 80)) MaxLevel = 2;
		if ((click_y >= 81) && (click_y <= 120)) MaxLevel = 3;
		if ((click_y >= 121) && (click_y <= 160)) MaxLevel = 4;
		break;
	case 5:
		if ((click_y >= 0) && (click_y <= 40)) MaxLevel = 1;
		if ((click_y >= 41) && (click_y <= 80)) MaxLevel = 2;
		if ((click_y >= 81) && (click_y <= 120)) MaxLevel = 3;
		if ((click_y >= 121) && (click_y <= 160)) MaxLevel = 4;
		if ((click_y >= 161) && (click_y <= 180)) MaxLevel = 5;
		break;
	case 6:
		if ((click_y >= 0) && (click_y <= 40)) MaxLevel = 1;
		if ((click_y >= 41) && (click_y <= 80)) MaxLevel = 2;
		if ((click_y >= 81) && (click_y <= 120)) MaxLevel = 3;
		if ((click_y >= 121) && (click_y <= 160)) MaxLevel = 4;
		if ((click_y >= 161) && (click_y <= 180)) MaxLevel = 5;
		if ((click_y >= 181) && (click_y <= 200)) MaxLevel = 6;
		break;
	case 7:
		if ((click_y >= 0) && (click_y <= 40)) MaxLevel = 1;
		if ((click_y >= 41) && (click_y <= 80)) MaxLevel = 2;
		if ((click_y >= 81) && (click_y <= 120)) MaxLevel = 3;
		if ((click_y >= 121) && (click_y <= 160)) MaxLevel = 4;
		if ((click_y >= 161) && (click_y <= 180)) MaxLevel = 5;
		if ((click_y >= 181) && (click_y <= 200)) MaxLevel = 6;
		if ((click_y >= 201) && (click_y <= 240)) MaxLevel = 7;
		break;
	case 8:
		if ((click_y >= 0) && (click_y <= 40)) MaxLevel = 1;
		if ((click_y >= 41) && (click_y <= 80)) MaxLevel = 2;
		if ((click_y >= 81) && (click_y <= 120)) MaxLevel = 3;
		if ((click_y >= 121) && (click_y <= 160)) MaxLevel = 4;
		if ((click_y >= 161) && (click_y <= 180)) MaxLevel = 5;
		if ((click_y >= 181) && (click_y <= 200)) MaxLevel = 6;
		if ((click_y >= 201) && (click_y <= 240)) MaxLevel = 7;
		if ((click_y >= 241) && (click_y <= 280)) MaxLevel = 8;
		break;
	}
		float X1, Y1, X2, Y2, X3, Y3;
	X1 = 50;
	Y1 = 200;
	X2 = 200;
	Y2 = 200;
	Y3 = (Y2 + Y1) / 2 + (X1 - X2)*sqrt(3.0) / 2;
	X3 = (X2 + X1) / 2 + (Y2 - Y1)*sqrt(3.0) / 2;
	Tree_Node ^side1, ^side2, ^side3;
	side1 = gcnew Tree_Node(X1, Y1, X2, Y2, (pictureBox2->Width / 2), (start_height / 2), (pictureBox2->Height / 7), 1);
	generate_tree(side1);

	side2 = gcnew Tree_Node(X3, Y3, X1, Y1, (pictureBox2->Width / 2), (start_height / 2), (pictureBox2->Height / 7), 1);
	generate_tree(side2);

	side3 = gcnew Tree_Node(X2, Y2, X3, Y3, (pictureBox2->Width / 2), (start_height / 2), (pictureBox2->Height / 7), 1);
	generate_tree(side3);
	paint_clear_fract();
	Graphics^ Графика = pictureBox1->CreateGraphics();
	paint_fractal(side1, Графика, true);
	paint_fractal(side2, Графика, true);
	paint_fractal(side3, Графика, true);
}
};
}
