#pragma once

#include "func.h"

namespace asd
{
    using namespace System;
    using namespace System::Runtime::InteropServices;
    using namespace System::ComponentModel;
    using namespace System::Collections;
    using namespace System::Windows::Forms;
    using namespace System::Data;
    using namespace System::Drawing;

    public ref class Form1 : public System::Windows::Forms::Form
    {
        public:
            Form1(void)
            {
                InitializeComponent();
            }

        protected:
            ~Form1()
            {
                if (components)
                {
                    delete components;
                }
            }

        private: System::Windows::Forms::Button^  button1;
        private: System::Windows::Forms::TextBox^  textBox1;
        private: System::Windows::Forms::Label^  label1;
        private: System::Windows::Forms::DataVisualization::Charting::Chart^  chart1;
        private: System::Windows::Forms::OpenFileDialog^  openFileDialog1;
	private: System::Windows::Forms::Button^  button2;

        private:
            System::ComponentModel::Container ^components;

    #pragma region Windows Form Designer generated code
            void InitializeComponent(void)
            {
				System::Windows::Forms::DataVisualization::Charting::ChartArea^  chartArea1 = (gcnew System::Windows::Forms::DataVisualization::Charting::ChartArea());
				System::Windows::Forms::DataVisualization::Charting::Series^  series1 = (gcnew System::Windows::Forms::DataVisualization::Charting::Series());
				System::Windows::Forms::DataVisualization::Charting::Series^  series2 = (gcnew System::Windows::Forms::DataVisualization::Charting::Series());
				this->button1 = (gcnew System::Windows::Forms::Button());
				this->openFileDialog1 = (gcnew System::Windows::Forms::OpenFileDialog());
				this->textBox1 = (gcnew System::Windows::Forms::TextBox());
				this->label1 = (gcnew System::Windows::Forms::Label());
				this->chart1 = (gcnew System::Windows::Forms::DataVisualization::Charting::Chart());
				this->button2 = (gcnew System::Windows::Forms::Button());
				(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->chart1))->BeginInit();
				this->SuspendLayout();
				// 
				// button1
				// 
				this->button1->Location = System::Drawing::Point(12, 12);
				this->button1->Name = L"button1";
				this->button1->Size = System::Drawing::Size(130, 40);
				this->button1->TabIndex = 0;
				this->button1->Text = L"Построить";
				this->button1->UseVisualStyleBackColor = true;
				this->button1->Click += gcnew System::EventHandler(this, &Form1::button1_Click);
				// 
				// openFileDialog1
				// 
				this->openFileDialog1->FileName = L"openFileDialog1";
				this->openFileDialog1->Filter = L"txt files (*.txt)|*.txt";
				// 
				// textBox1
				// 
				this->textBox1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12));
				this->textBox1->Location = System::Drawing::Point(422, 6);
				this->textBox1->Name = L"textBox1";
				this->textBox1->Size = System::Drawing::Size(73, 35);
				this->textBox1->TabIndex = 2;
				this->textBox1->Text = L"1";
				// 
				// label1
				// 
				this->label1->AutoSize = true;
				this->label1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12));
				this->label1->Location = System::Drawing::Point(178, 12);
				this->label1->Name = L"label1";
				this->label1->Size = System::Drawing::Size(238, 29);
				this->label1->TabIndex = 3;
				this->label1->Text = L"Степень полинома";
				// 
				// chart1
				// 
				chartArea1->Name = L"ChartArea1";
				this->chart1->ChartAreas->Add(chartArea1);
				this->chart1->Location = System::Drawing::Point(12, 58);
				this->chart1->Name = L"chart1";
				series1->ChartArea = L"ChartArea1";
				series1->ChartType = System::Windows::Forms::DataVisualization::Charting::SeriesChartType::Line;
				series1->Color = System::Drawing::Color::Red;
				series1->Name = L"Series1";
				series2->ChartArea = L"ChartArea1";
				series2->ChartType = System::Windows::Forms::DataVisualization::Charting::SeriesChartType::Point;
				series2->Name = L"Series2";
				this->chart1->Series->Add(series1);
				this->chart1->Series->Add(series2);
				this->chart1->Size = System::Drawing::Size(918, 597);
				this->chart1->TabIndex = 1;
				this->chart1->Text = L"chart1";
				// 
				// button2
				// 
				this->button2->Location = System::Drawing::Point(800, 12);
				this->button2->Name = L"button2";
				this->button2->Size = System::Drawing::Size(130, 40);
				this->button2->TabIndex = 4;
				this->button2->Text = L"Файл";
				this->button2->UseVisualStyleBackColor = true;
				this->button2->Click += gcnew System::EventHandler(this, &Form1::button2_Click);
				// 
				// Form1
				// 
				this->AutoScaleDimensions = System::Drawing::SizeF(9, 20);
				this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
				this->ClientSize = System::Drawing::Size(942, 667);
				this->Controls->Add(this->button2);
				this->Controls->Add(this->label1);
				this->Controls->Add(this->textBox1);
				this->Controls->Add(this->chart1);
				this->Controls->Add(this->button1);
				this->Name = L"Form1";
				this->Text = L"Form1";
				(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->chart1))->EndInit();
				this->ResumeLayout(false);
				this->PerformLayout();

			}
	static char *filename = "C:/Users/Maksim/Pictures/lab_04/lab_04/lab_04/lab_04/f_src_3.txt";
    #pragma endregion
        private: System::Void button1_Click(System::Object^  sender, System::EventArgs^  e)
        {
            int degree = Convert::ToInt32(textBox1->Text);
            struct table_s *table = get_table(filename, degree);

            if (table->arg)
            {
            chart1->Series[0]->Points->Clear();
            chart1->Series[1]->Points->Clear();

            for (double i = table->x[0]; i < table->x[table->cn - 1]; i = i + 0.01)
            chart1->Series[0]->Points->AddXY(i, get_p(table, i));

            for (int i = 0; i < table->cn; i++)
                chart1->Series[1]->Points->AddXY(table->x[i], table->y[i]);
            }
            else
                MessageBox::Show("Не удалось построить");

            free_table(table);
        }
		private: System::Void button2_Click(System::Object^  sender, System::EventArgs^  e)
		{
			if (this->openFileDialog1->ShowDialog() == Windows::Forms::DialogResult::OK)
			{
				filename = (char*)(void*)Marshal::StringToHGlobalAnsi(this->openFileDialog1->FileName);
			}
		}
	};
}

