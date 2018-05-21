#pragma once

#include "readData.h"
#include "func.h"
#include <string.h>

namespace lab_07 {

    sData *table = NULL;

    using namespace System;
    using namespace System::ComponentModel;
    using namespace System::Collections;
    using namespace System::Windows::Forms;
    using namespace System::Data;
    using namespace System::Drawing;

    /// <summary>
    /// Сводка для mainForm
    /// </summary>
    public ref class mainForm : public System::Windows::Forms::Form
    {
    public:
        mainForm(void)
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
        ~mainForm()
        {
            if (components)
            {
                delete components;
            }
        }
    private: System::Windows::Forms::DataGridView^  dataGridView;
    protected: 

    protected: 







    private: System::Windows::Forms::Button^  button1;
    private: System::Windows::Forms::OpenFileDialog^  dlgOpen;









    private: System::Windows::Forms::TextBox^  textBox1;
    private: System::Windows::Forms::TextBox^  textBox2;
    private: System::Windows::Forms::TextBox^  textBox3;
    private: System::Windows::Forms::TextBox^  textBox4;
    private: System::Windows::Forms::TextBox^  textBox5;
    private: System::Windows::Forms::TextBox^  textBox6;
    private: System::Windows::Forms::Button^  button2;
    private: System::Windows::Forms::TextBox^  textBox7;
    private: System::Windows::Forms::Label^  label1;
    private: System::Windows::Forms::Label^  label2;
    private: System::Windows::Forms::Label^  label3;
    private: System::Windows::Forms::Label^  label4;
    private: System::Windows::Forms::Label^  label5;
    private: System::Windows::Forms::Label^  label6;
    private: System::Windows::Forms::Label^  label7;
    private: System::Windows::Forms::DataGridViewTextBoxColumn^  ColumnX;
    private: System::Windows::Forms::DataGridViewTextBoxColumn^  ColumnY;
    private: System::Windows::Forms::DataGridViewTextBoxColumn^  ColumnLeft;
    private: System::Windows::Forms::DataGridViewTextBoxColumn^  ColumnRight;
    private: System::Windows::Forms::DataGridViewTextBoxColumn^  ColumnCentral;
    private: System::Windows::Forms::DataGridViewTextBoxColumn^  ColumnExtreme;
    private: System::Windows::Forms::DataGridViewTextBoxColumn^  ColumnRungeL;
    private: System::Windows::Forms::DataGridViewTextBoxColumn^  ColumnRungeR;
    private: System::Windows::Forms::DataGridViewTextBoxColumn^  ColumnAlignment;

    private:
        /// <summary>
        /// Требуется переменная конструктора.
        /// </summary>
        System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
        /// <summary>
        /// Обязательный метод для поддержки конструктора - не изменяйте
        /// содержимое данного метода при помощи редактора кода.
        /// </summary>
        void InitializeComponent(void)
        {
			this->dataGridView = (gcnew System::Windows::Forms::DataGridView());
			this->ColumnX = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->ColumnY = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->ColumnLeft = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->ColumnRight = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->ColumnCentral = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->ColumnExtreme = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->ColumnRungeL = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->ColumnRungeR = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->ColumnAlignment = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->dlgOpen = (gcnew System::Windows::Forms::OpenFileDialog());
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->textBox2 = (gcnew System::Windows::Forms::TextBox());
			this->textBox3 = (gcnew System::Windows::Forms::TextBox());
			this->textBox4 = (gcnew System::Windows::Forms::TextBox());
			this->textBox5 = (gcnew System::Windows::Forms::TextBox());
			this->textBox6 = (gcnew System::Windows::Forms::TextBox());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->textBox7 = (gcnew System::Windows::Forms::TextBox());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->label6 = (gcnew System::Windows::Forms::Label());
			this->label7 = (gcnew System::Windows::Forms::Label());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->dataGridView))->BeginInit();
			this->SuspendLayout();
			// 
			// dataGridView
			// 
			this->dataGridView->AllowUserToAddRows = false;
			this->dataGridView->AllowUserToDeleteRows = false;
			this->dataGridView->AutoSizeColumnsMode = System::Windows::Forms::DataGridViewAutoSizeColumnsMode::DisplayedCells;
			this->dataGridView->AutoSizeRowsMode = System::Windows::Forms::DataGridViewAutoSizeRowsMode::DisplayedCells;
			this->dataGridView->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->dataGridView->Columns->AddRange(gcnew cli::array< System::Windows::Forms::DataGridViewColumn^  >(9) {this->ColumnX, 
				this->ColumnY, this->ColumnLeft, this->ColumnRight, this->ColumnCentral, this->ColumnExtreme, this->ColumnRungeL, this->ColumnRungeR, 
				this->ColumnAlignment});
			this->dataGridView->Location = System::Drawing::Point(12, 12);
			this->dataGridView->Name = L"dataGridView";
			this->dataGridView->ReadOnly = true;
			this->dataGridView->RowTemplate->Height = 28;
			this->dataGridView->Size = System::Drawing::Size(1271, 614);
			this->dataGridView->TabIndex = 0;
			this->dataGridView->CellContentClick += gcnew System::Windows::Forms::DataGridViewCellEventHandler(this, &mainForm::dataGridView_CellContentClick);
			// 
			// ColumnX
			// 
			this->ColumnX->AutoSizeMode = System::Windows::Forms::DataGridViewAutoSizeColumnMode::DisplayedCells;
			this->ColumnX->HeaderText = L"X";
			this->ColumnX->Name = L"ColumnX";
			this->ColumnX->ReadOnly = true;
			this->ColumnX->SortMode = System::Windows::Forms::DataGridViewColumnSortMode::NotSortable;
			this->ColumnX->Width = 26;
			// 
			// ColumnY
			// 
			this->ColumnY->AutoSizeMode = System::Windows::Forms::DataGridViewAutoSizeColumnMode::DisplayedCells;
			this->ColumnY->HeaderText = L"Y";
			this->ColumnY->Name = L"ColumnY";
			this->ColumnY->ReadOnly = true;
			this->ColumnY->SortMode = System::Windows::Forms::DataGridViewColumnSortMode::NotSortable;
			this->ColumnY->Width = 26;
			// 
			// ColumnLeft
			// 
			this->ColumnLeft->AutoSizeMode = System::Windows::Forms::DataGridViewAutoSizeColumnMode::DisplayedCells;
			this->ColumnLeft->HeaderText = L"Левые производные";
			this->ColumnLeft->Name = L"ColumnLeft";
			this->ColumnLeft->ReadOnly = true;
			this->ColumnLeft->SortMode = System::Windows::Forms::DataGridViewColumnSortMode::NotSortable;
			this->ColumnLeft->Width = 154;
			// 
			// ColumnRight
			// 
			this->ColumnRight->AutoSizeMode = System::Windows::Forms::DataGridViewAutoSizeColumnMode::DisplayedCells;
			this->ColumnRight->HeaderText = L"Правые производные";
			this->ColumnRight->Name = L"ColumnRight";
			this->ColumnRight->ReadOnly = true;
			this->ColumnRight->SortMode = System::Windows::Forms::DataGridViewColumnSortMode::NotSortable;
			this->ColumnRight->Width = 162;
			// 
			// ColumnCentral
			// 
			this->ColumnCentral->AutoSizeMode = System::Windows::Forms::DataGridViewAutoSizeColumnMode::DisplayedCells;
			this->ColumnCentral->HeaderText = L"Центральные производные";
			this->ColumnCentral->Name = L"ColumnCentral";
			this->ColumnCentral->ReadOnly = true;
			this->ColumnCentral->SortMode = System::Windows::Forms::DataGridViewColumnSortMode::NotSortable;
			this->ColumnCentral->Width = 203;
			// 
			// ColumnExtreme
			// 
			this->ColumnExtreme->AutoSizeMode = System::Windows::Forms::DataGridViewAutoSizeColumnMode::DisplayedCells;
			this->ColumnExtreme->HeaderText = L"Y0\' / Yn\'";
			this->ColumnExtreme->Name = L"ColumnExtreme";
			this->ColumnExtreme->ReadOnly = true;
			this->ColumnExtreme->SortMode = System::Windows::Forms::DataGridViewColumnSortMode::NotSortable;
			this->ColumnExtreme->Width = 66;
			// 
			// ColumnRungeL
			// 
			this->ColumnRungeL->AutoSizeMode = System::Windows::Forms::DataGridViewAutoSizeColumnMode::DisplayedCells;
			this->ColumnRungeL->HeaderText = L"Формула Рунге(лев)";
			this->ColumnRungeL->Name = L"ColumnRungeL";
			this->ColumnRungeL->ReadOnly = true;
			this->ColumnRungeL->SortMode = System::Windows::Forms::DataGridViewColumnSortMode::NotSortable;
			this->ColumnRungeL->Width = 152;
			// 
			// ColumnRungeR
			// 
			this->ColumnRungeR->AutoSizeMode = System::Windows::Forms::DataGridViewAutoSizeColumnMode::DisplayedCells;
			this->ColumnRungeR->HeaderText = L"Формула Рунге(пр)";
			this->ColumnRungeR->Name = L"ColumnRungeR";
			this->ColumnRungeR->ReadOnly = true;
			this->ColumnRungeR->SortMode = System::Windows::Forms::DataGridViewColumnSortMode::NotSortable;
			this->ColumnRungeR->Width = 143;
			// 
			// ColumnAlignment
			// 
			this->ColumnAlignment->AutoSizeMode = System::Windows::Forms::DataGridViewAutoSizeColumnMode::DisplayedCells;
			this->ColumnAlignment->HeaderText = L"Выравнивающие переменные";
			this->ColumnAlignment->Name = L"ColumnAlignment";
			this->ColumnAlignment->ReadOnly = true;
			this->ColumnAlignment->SortMode = System::Windows::Forms::DataGridViewColumnSortMode::NotSortable;
			this->ColumnAlignment->Width = 217;
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(1289, 12);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(138, 49);
			this->button1->TabIndex = 1;
			this->button1->Text = L"Загрузить";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &mainForm::button1_Click);
			// 
			// dlgOpen
			// 
			this->dlgOpen->FileName = L"fileName";
			// 
			// textBox1
			// 
			this->textBox1->Location = System::Drawing::Point(1289, 191);
			this->textBox1->Name = L"textBox1";
			this->textBox1->Size = System::Drawing::Size(138, 26);
			this->textBox1->TabIndex = 2;
			this->textBox1->Visible = false;
			// 
			// textBox2
			// 
			this->textBox2->Location = System::Drawing::Point(1289, 223);
			this->textBox2->Name = L"textBox2";
			this->textBox2->Size = System::Drawing::Size(138, 26);
			this->textBox2->TabIndex = 3;
			this->textBox2->Visible = false;
			// 
			// textBox3
			// 
			this->textBox3->Location = System::Drawing::Point(1289, 255);
			this->textBox3->Name = L"textBox3";
			this->textBox3->Size = System::Drawing::Size(138, 26);
			this->textBox3->TabIndex = 4;
			this->textBox3->Visible = false;
			// 
			// textBox4
			// 
			this->textBox4->Location = System::Drawing::Point(1289, 351);
			this->textBox4->Name = L"textBox4";
			this->textBox4->Size = System::Drawing::Size(138, 26);
			this->textBox4->TabIndex = 7;
			this->textBox4->Visible = false;
			// 
			// textBox5
			// 
			this->textBox5->Location = System::Drawing::Point(1289, 319);
			this->textBox5->Name = L"textBox5";
			this->textBox5->Size = System::Drawing::Size(138, 26);
			this->textBox5->TabIndex = 6;
			this->textBox5->Visible = false;
			// 
			// textBox6
			// 
			this->textBox6->Location = System::Drawing::Point(1289, 287);
			this->textBox6->Name = L"textBox6";
			this->textBox6->Size = System::Drawing::Size(138, 26);
			this->textBox6->TabIndex = 5;
			this->textBox6->Visible = false;
			// 
			// button2
			// 
			this->button2->Location = System::Drawing::Point(1289, 415);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(138, 43);
			this->button2->TabIndex = 8;
			this->button2->Text = L"Создать";
			this->button2->UseVisualStyleBackColor = true;
			this->button2->Visible = false;
			this->button2->Click += gcnew System::EventHandler(this, &mainForm::button2_Click);
			// 
			// textBox7
			// 
			this->textBox7->Location = System::Drawing::Point(1289, 383);
			this->textBox7->Name = L"textBox7";
			this->textBox7->Size = System::Drawing::Size(138, 26);
			this->textBox7->TabIndex = 9;
			this->textBox7->Visible = false;
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(1433, 194);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(27, 20);
			this->label1->TabIndex = 10;
			this->label1->Text = L"a0";
			this->label1->Visible = false;
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(1433, 226);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(27, 20);
			this->label2->TabIndex = 11;
			this->label2->Text = L"a1";
			this->label2->Visible = false;
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Location = System::Drawing::Point(1433, 258);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(27, 20);
			this->label3->TabIndex = 13;
			this->label3->Text = L"a2";
			this->label3->Visible = false;
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Location = System::Drawing::Point(1433, 290);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(29, 20);
			this->label4->TabIndex = 12;
			this->label4->Text = L"X0";
			this->label4->Visible = false;
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->Location = System::Drawing::Point(1433, 322);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(29, 20);
			this->label5->TabIndex = 15;
			this->label5->Text = L"Xn";
			this->label5->Visible = false;
			// 
			// label6
			// 
			this->label6->AutoSize = true;
			this->label6->Location = System::Drawing::Point(1433, 354);
			this->label6->Name = L"label6";
			this->label6->Size = System::Drawing::Size(38, 20);
			this->label6->TabIndex = 14;
			this->label6->Text = L"Шаг";
			this->label6->Visible = false;
			// 
			// label7
			// 
			this->label7->AutoSize = true;
			this->label7->Location = System::Drawing::Point(1433, 386);
			this->label7->Name = L"label7";
			this->label7->Size = System::Drawing::Size(76, 20);
			this->label7->TabIndex = 16;
			this->label7->Text = L"FileName";
			this->label7->Visible = false;
			// 
			// mainForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(9, 20);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->AutoSize = true;
			this->ClientSize = System::Drawing::Size(1509, 638);
			this->Controls->Add(this->label7);
			this->Controls->Add(this->label5);
			this->Controls->Add(this->label6);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->label4);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->textBox7);
			this->Controls->Add(this->button2);
			this->Controls->Add(this->textBox4);
			this->Controls->Add(this->textBox5);
			this->Controls->Add(this->textBox6);
			this->Controls->Add(this->textBox3);
			this->Controls->Add(this->textBox2);
			this->Controls->Add(this->textBox1);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->dataGridView);
			this->Name = L"mainForm";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"mainForm";
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->dataGridView))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
    private: System::Void button1_Click(System::Object^  sender, System::EventArgs^  e) {
                 dlgOpen->InitialDirectory = "D:/msys64/home/Sultan/work/VA/lab_07";
                 dlgOpen->Title = "Исходные данные";
                 dlgOpen->Filter = "Текстовые файлы (*.txt)|*.txt";
                 dlgOpen->FilterIndex = 1;
                 if (dlgOpen->ShowDialog() == Windows::Forms::DialogResult::OK)
                 {
                     char *fileName = (char*)(void*)System::Runtime::InteropServices::Marshal::StringToHGlobalAnsi(dlgOpen->FileName);
                     sData *tempTable = getTable(fileName);
                     System::Runtime::InteropServices::Marshal::FreeHGlobal((IntPtr)fileName);

                     if (tempTable)
                     {
                         if (table)
                         {
                             free(table->data);
                             free(table);
                         }

                         table = tempTable;
                         fillTable(table);

                         while (dataGridView->RowCount != 0)
                             dataGridView->Rows->RemoveAt(0);

                         for (int i = 0; i < table->n; i++)
                         {
                             dataGridView->Rows->Add();

							 //unsigned long nan[2] = {0xffffffff, 0x7fffffff};
                             for (int j = 0; j < 9; j++)
							 {
								 if (table->data[i][j] != getNAN(1))//*(double*)nan)
									dataGridView->Rows[i]->Cells[j]->Value = Convert::ToString(table->data[i][j]);
								 else
									 dataGridView->Rows[i]->Cells[j]->Value = "-";
							 }


                             /*
                             if (i == 0)
                             dataGridView->Rows[i]->Cells[2]->Value = "NAN";

                             if (i == table->n - 1)
                             dataGridView->Rows[i]->Cells[3]->Value = "NAN";

                             if ((i != 0) && (i != table->n - 1))
                             {
                             dataGridView->Rows[i]->Cells[4]->Value = "NAN";
                             dataGridView->Rows[i]->Cells[5]->Value = "NAN";
                             }

                             if (i < 2)
                             dataGridView->Rows[i]->Cells[6]->Value = "NAN";

                             if (i > table->n - 3)
                             dataGridView->Rows[i]->Cells[7]->Value = "NAN";


                             */
                         }
                     }
                 }
             }
    private: System::Void button2_Click(System::Object^  sender, System::EventArgs^  e) {
                 char *fileName = (char*)(void*)System::Runtime::InteropServices::Marshal::StringToHGlobalAnsi(textBox7->Text);
                 char str[100] = "D:/msys64/home/Sultan/work/VA/lab_07/";
                 std::ofstream fDst(strcat(str, fileName));
                 System::Runtime::InteropServices::Marshal::FreeHGlobal((IntPtr)fileName);
                 
                 double x0 = Convert::ToDouble(textBox6->Text);
                 double xn = Convert::ToDouble(textBox5->Text);
                 double h = Convert::ToDouble(textBox4->Text);
                 double a[3] = { Convert::ToDouble(textBox1->Text), Convert::ToDouble(textBox2->Text), Convert::ToDouble(textBox3->Text) };
                 int n = (xn - x0) / h;

                 fDst << n << std::endl;

                 int i = 0;

                 for (double x = x0; x < xn && i < n; x += h, i++)
                     fDst << x << ' ' << f(x, a) << std::endl;

                 fDst.close();
             }
	private: System::Void dataGridView_CellContentClick(System::Object^  sender, System::Windows::Forms::DataGridViewCellEventArgs^  e) {
			 }
};
}
