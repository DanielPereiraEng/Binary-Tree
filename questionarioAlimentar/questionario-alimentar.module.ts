import { NgModule } from '@angular/core';
import { CommonModule } from '@angular/common';
import { FormsModule } from '@angular/forms';
import { MatDialogModule } from '@angular/material/dialog';
import { MatButtonModule } from '@angular/material/button';
import { MatRadioModule } from '@angular/material/radio';
import { QuestionPageComponent } from './question-page/question-page.component';
import { QuestionDialogComponent } from './question-dialog/question-dialog.component';

@NgModule({
  declarations: [
    QuestionPageComponent,
    QuestionDialogComponent
  ],
  imports: [
    CommonModule,
    FormsModule,
    MatDialogModule,
    MatButtonModule,
    MatRadioModule
  ],
  exports: [
    QuestionPageComponent
  ]
})
export class QuestionarioAlimentarModule { }
