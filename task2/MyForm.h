#pragma once
#include "Tree.h"
#include "math.h"
namespace task2 {
	int MaxLevel=10;
	int start_height = 40;
	bool check = true;

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
			this->pictureBox1->Location = System::Drawing::Point(0, 0);
			this->pictureBox1->Name = L"pictureBox1";
			this->pictureBox1->Size = System::Drawing::Size(308, 265);
			this->pictureBox1->TabIndex = 0;
			this->pictureBox1->TabStop = false;
			// 
			// pictureBox2
			// 
			this->pictureBox2->Location = System::Drawing::Point(308, 0);
			this->pictureBox2->Name = L"pictureBox2";
			this->pictureBox2->Size = System::Drawing::Size(330, 265);
			this->pictureBox2->TabIndex = 1;
			this->pictureBox2->TabStop = false;
			// 
			// textBox1
			// 
			this->textBox1->Location = System::Drawing::Point(287, 299);
			this->textBox1->Name = L"textBox1";
			this->textBox1->Size = System::Drawing::Size(49, 20);
			this->textBox1->TabIndex = 2;
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(211, 302);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(70, 13);
			this->label1->TabIndex = 3;
			this->label1->Text = L"max уровень";
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(232, 323);
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
			this->ClientSize = System::Drawing::Size(639, 358);
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
		private: void Paint_tree(Tree_Node ^tree, Point top, Point left, Point right, Graphics ^Графика)
		{

			Color CurrentColor;
			CurrentColor = choose_color(tree->level);

			Pen^ Перо;
			Перо = gcnew Pen(CurrentColor);
			array<Point>^ curvePoints;
			curvePoints = gcnew array<Point>(3);

			curvePoints[0] = top;
			curvePoints[1] = right;
			curvePoints[2] = left;
			Графика->DrawPolygon(Перо, curvePoints);

		}

		private: void Paint_TreeBrunch(Tree_Node ^tree, Graphics ^Grafica, Color ^SomeStrangeColor)
		{
			Color CurrentColor;
			CurrentColor = choose_color(tree->level);
			Brush^ Заливка = gcnew SolidBrush(CurrentColor);
			Grafica->FillEllipse(Заливка, tree->treeX - (7 - tree->level), tree->treeY - (7 - tree->level), 2 * (7 - tree->level), 2 * (7 - tree->level));
		}

		private: void Paint_Tree(Tree_Node ^tree, Graphics ^Grafica)
		{
			Color CurrentColor;
			CurrentColor = choose_color(tree->level);
			Paint_TreeBrunch(tree, Grafica, CurrentColor);
			if (tree->level != MaxLevel)
			{
				Pen^ brush = gcnew Pen(CurrentColor);
				Grafica->DrawLine(brush, tree->treeX, tree->treeY, tree->next_one->treeX, tree->next_one->treeY);
				Paint_Tree(tree->next_one, Grafica);
				Grafica->DrawLine(brush, tree->treeX, tree->treeY, tree->next_two->treeX, tree->next_two->treeY);
				Paint_Tree(tree->next_two, Grafica);
				CurrentColor = Color::White;
				Grafica->DrawLine(brush, tree->treeX, tree->treeY, tree->next_three->treeX, tree->next_three->treeY);
				Paint_Tree(tree->next_three, Grafica);

			}
		}
		private: void Generate_Tree(Tree_Node ^tree)
		{
			if (tree->level != MaxLevel)
			{
				Tree_Node ^p;
				//int NewRadius = (Sphere->Radius / 2);

				int NewLevel = (tree->level + 1);
				int x_s = (tree->x2 + tree->x1) / 2;
				int y_s = (tree->y2 + tree->y1) / 2;
				p = gcnew Tree_Node((4*x_s - tree->x3)/3, (4 * y_s - tree->y3) / 3,
					((2*tree->x1+tree->x2)/3), ((2 * tree->y1 + tree->y2) / 3), ((2 * tree->x2 + tree->x1) / 3), ((2 * tree->y2 + tree->y1) / 3),tree->treeX - (3 * tree->treeX_dif), tree->treeY + start_height, (tree->treeX_dif / 3),NewLevel);
				tree->next_one = p;
				Generate_Tree(tree->next_one);
				y_s = (tree->y3 + tree->y1) / 2;
				x_s = (tree->x3 + tree->x1) / 2;
				p = gcnew Tree_Node((4 * x_s - tree->x2) / 3, (4 * y_s - tree->y2) / 3,
					((2 * tree->x1 + tree->x3) / 3), ((2 * tree->y1 + tree->y3) / 3), ((2 * tree->x3 + tree->x1) / 3), ((2 * tree->y3 + tree->y1) / 3), tree->treeX , tree->treeY + start_height, (tree->treeX_dif / 3), NewLevel);
				tree->next_two = p;
				Generate_Tree(tree->next_two);
				y_s = (tree->y2 + tree->y3) / 2;
				x_s = (tree->x2 + tree->x3) / 2;
				p = gcnew Tree_Node((4 * x_s - tree->x1) / 3, (4 * y_s - tree->y1) / 3,
					((2 * tree->x3 + tree->x2) / 3), ((2 * tree->y3 + tree->y2) / 3), ((2 * tree->x2 + tree->x3) / 3), ((2 * tree->y2 + tree->y3) / 3), 
					 tree->treeX + (3 * tree->treeX_dif), tree->treeY + start_height, (tree->treeX_dif / 3), NewLevel);
				tree->next_three = p;
				Generate_Tree(tree->next_three);

			}
		}

		//рисуем фрактал
		private: void draw_part_of_fractal(Tree_Node ^tree, Point top, Point left, Point right, Graphics ^Графика)
		{

			Color CurrentColor;
			CurrentColor = choose_color(tree->level);

			Pen^ Перо;
			Перо = gcnew Pen(CurrentColor);
			array<Point>^ curvePoints;
			curvePoints = gcnew array<Point>(3);

			curvePoints[0] = top;
			curvePoints[1] = right;
			curvePoints[2] = left;
			Графика->DrawLine(Перо, curvePoints[0], curvePoints[1]);
			Графика->DrawLine(Перо, curvePoints[2], curvePoints[1]);
			/*(if (check>1)
			{
				CurrentColor = Color::White;
				Pen^ Перо2;
				Перо2 = gcnew Pen(CurrentColor);
				Графика->DrawLine(Перо2, curvePoints[2], curvePoints[0]);
			} else*/
			Графика->DrawLine(Перо, curvePoints[2], curvePoints[0]);

		}

	private: void paint_fractal(Tree_Node ^tree, Graphics^ Графика)
	{
		Point top = Point(tree->x3, tree->y3);
		Point left = Point(tree->x2, tree->y2);
		Point right = Point(tree->x1, tree->y1);
		//int Level = tree->level;
		draw_part_of_fractal(tree,top, left, right, Графика);
		if (tree->level != MaxLevel)
		{
			paint_fractal(tree->next_one, Графика);
			paint_fractal(tree->next_two, Графика);
			paint_fractal(tree->next_three, Графика);
		
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
		if (MaxLevel > 10) { error(MaxLevel); MaxLevel = 10; }
		int X1, Y1, X2, Y2, X3, Y3;
		X1 = 50;
		Y1 = 200;
		X2 = 200;
		Y2 = 200;

		int x_s_ = (X2+ X1) / 2;
		int y_s_ = (Y2 + Y1) / 2;
		Y3 = Y2-(X2 - X1)*sqrt(3.0) / 2;
		X3 = X1+(X2 - X1) / 2;
		Tree_Node ^tree;
		tree = gcnew Tree_Node(X1, Y1,X2,Y2,X3,Y3, (710 / 2), (start_height / 2), (400 / 7),1);
		Generate_Tree(tree);
		Bitmap ^SomeStrangeTreebitmab = gcnew Bitmap(pictureBox2->Width, pictureBox2->Height);
		Graphics^ GraphikaBitmap = Graphics::FromImage(SomeStrangeTreebitmab);
		GraphikaBitmap->Clear(Color::White);
		Paint_Tree(tree, GraphikaBitmap);
		pictureBox2->Image = SomeStrangeTreebitmab;

		/*SomeStrangeSphere ^SphereHead2;
		int radius2 = 85;
		int StartingHeight2 = 10;
		SphereHead2 = gcnew SomeStrangeSphere(radius2, 1, 90, 90, (180 / 2), (StartingHeight2 / 2), (180 / 7));
		Generate_Tree(SphereHead2);
		*/

		Graphics^ Графика2 = pictureBox1->CreateGraphics();
		paint_fractal(tree, Графика2);

		/*SomeStrangeSphere ^SphereHead3;
		int radius3 = 49;
		int StartingHeight3 = 10;
		SphereHead3 = gcnew SomeStrangeSphere(radius3, 1, 50, 50, (100 / 2), (StartingHeight3 / 2), (100 / 7));
		Generate_Tree(SphereHead3);
		Graphics^ Графика3 = pictureBox4->CreateGraphics();
		Paint_Phractal(SphereHead3, Графика3);*/

	}
};
}
