import { Component } from '@angular/core';
import { MatDialog } from '@angular/material/dialog';
import { QuestionDialogComponent } from '../question-dialog/question-dialog.component';

export interface Question {
  id: number;
  questionText: string;
  ageGroup: string;
  options: string[];
  answer: string;
}

@Component({
  selector: 'app-question-page',
  templateUrl: './question-page.component.html',
  styleUrls: ['./question-page.component.scss']
})
export class QuestionPageComponent {
selectAgeGroup(arg0: string) {
throw new Error('Method not implemented.');
}
  ageGroup: string = '0-6'; // Valor inicial da faixa etária
  questions: Question[] = [
    // Perguntas para 0 a 6 meses
    { id: 1, questionText: 'A criança ontem tomou leite do peito?', ageGroup: '0-6', options: ['Sim', 'Não', 'Não Sabe'], answer: '' },
    { id: 2, questionText: 'Ontem a criança consumiu Mingau?', ageGroup: '0-6', options: ['Sim', 'Não', 'Não Sabe'], answer: '' },
    { id: 3, questionText: 'Ontem a criança consumiu Água/chá?', ageGroup: '0-6', options: ['Sim', 'Não', 'Não Sabe'], answer: '' },
    { id: 4, questionText: 'Ontem a criança consumiu Leite de vaca?', ageGroup: '0-6', options: ['Sim', 'Não', 'Não Sabe'], answer: '' },
    { id: 5, questionText: 'Ontem a criança consumiu Fórmula infantil?', ageGroup: '0-6', options: ['Sim', 'Não', 'Não Sabe'], answer: '' },
    { id: 6, questionText: 'Ontem a criança consumiu Suco de fruta?', ageGroup: '0-6', options: ['Sim', 'Não', 'Não Sabe'], answer: '' },
    { id: 7, questionText: 'Ontem a criança consumiu Fruta?', ageGroup: '0-6', options: ['Sim', 'Não', 'Não Sabe'], answer: '' },
    { id: 8, questionText: 'Ontem a criança consumiu Comida de sal (de panela, papa ou sopa)?', ageGroup: '0-6', options: ['Sim', 'Não', 'Não Sabe'], answer: '' },
    { id: 9, questionText: 'Ontem a criança consumiu Outros alimentos/bebidas?', ageGroup: '0-6', options: ['Sim', 'Não', 'Não Sabe'], answer: '' },

    // Perguntas para 6 a 23 meses
    { id: 10, questionText: 'A criança ontem tomou leite do peito?', ageGroup: '6-23', options: ['Sim', 'Não', 'Não Sabe'], answer: '' },
    { id: 11, questionText: 'Ontem, a criança comeu fruta inteira, em pedaço ou amassada?', ageGroup: '6-23', options: ['Sim', 'Não', 'Não Sabe'], answer: '' },
    { id: 12, questionText: 'Se sim, quantas vezes?', ageGroup: '6-23', options: ['1 vez', '2 vezes', '3 vezes ou mais', 'Não Sabe'], answer: '' },
    { id: 13, questionText: 'Ontem a criança comeu comida de sal (de panela, papa ou sopa)?', ageGroup: '6-23', options: ['Sim', 'Não', 'Não Sabe'], answer: '' },
    { id: 14, questionText: 'Se sim, quantas vezes?', ageGroup: '6-23', options: ['1 vez', '2 vezes', '3 vezes ou mais', 'Não Sabe'], answer: '' },
    { id: 15, questionText: 'Se sim, essa comida foi oferecida:', ageGroup: '6-23', options: ['Em pedaços', 'Amassada', 'Passada na peneira', 'Liquidificada', 'Só o caldo', 'Não Sabe'], answer: '' },
    { id: 16, questionText: 'Ontem a criança consumiu Outro leite que não o leite do peito?', ageGroup: '6-23', options: ['Sim', 'Não', 'Não Sabe'], answer: '' },
    { id: 17, questionText: 'Ontem a criança consumiu Mingau com leite?', ageGroup: '6-23', options: ['Sim', 'Não', 'Não Sabe'], answer: '' },
    { id: 18, questionText: 'Ontem a criança consumiu Iogurte?', ageGroup: '6-23', options: ['Sim', 'Não', 'Não Sabe'], answer: '' },
    { id: 19, questionText: 'Ontem a criança consumiu Legumes (não considerar os utilizados como temperos, nem batata, mandioca/aipim/macaxeira, cará e inhame)?', ageGroup: '6-23', options: ['Sim', 'Não', 'Não Sabe'], answer: '' },
    { id: 20, questionText: 'Ontem a criança consumiu Vegetal ou fruta de cor alaranjada (abóbora ou jerimum, cenoura, mamão, manga) ou folhas verdes-escuras (couve, caruru, beldroega, bertalha, espinafre, mostarda)?', ageGroup: '6-23', options: ['Sim', 'Não', 'Não Sabe'], answer: '' },
    { id: 21, questionText: 'Ontem a criança consumiu Verdura de folha (alface, acelga, repolho)?', ageGroup: '6-23', options: ['Sim', 'Não', 'Não Sabe'], answer: '' },
    { id: 22, questionText: 'Ontem a criança consumiu Carne (boi, frango, peixe, porco, miúdos, outras) ou ovo?', ageGroup: '6-23', options: ['Sim', 'Não', 'Não Sabe'], answer: '' },
    { id: 23, questionText: 'Ontem a criança consumiu Fígado?', ageGroup: '6-23', options: ['Sim', 'Não', 'Não Sabe'], answer: '' },
    { id: 24, questionText: 'Ontem a criança consumiu Feijão?', ageGroup: '6-23', options: ['Sim', 'Não', 'Não Sabe'], answer: '' },
    { id: 25, questionText: 'Ontem a criança consumiu Arroz, batata, inhame, aipim/macaxeira/mandioca, farinha ou macarrão (sem ser instantâneo)?', ageGroup: '6-23', options: ['Sim', 'Não', 'Não Sabe'], answer: '' },
    { id: 26, questionText: 'Ontem a criança consumiu Hambúrguer e/ou embutidos (presunto, mortadela, salame, linguiça, salsicha)?', ageGroup: '6-23', options: ['Sim', 'Não', 'Não Sabe'], answer: '' },
    { id: 27, questionText: 'Ontem a criança consumiu Bebidas adoçadas (refrigerante, suco de caixinha, suco em pó, água de coco de caixinha, xaropes de guaraná/groselha, suco de fruta com adição de açúcar)?', ageGroup: '6-23', options: ['Sim', 'Não', 'Não Sabe'], answer: '' },
    { id: 28, questionText: 'Ontem a criança consumiu Macarrão instantâneo, salgadinhos de pacote ou biscoitos salgados?', ageGroup: '6-23', options: ['Sim', 'Não', 'Não Sabe'], answer: '' },
    { id: 29, questionText: 'Ontem a criança consumiu Biscoito recheado, doces ou guloseimas (balas, pirulitos, chiclete, caramelo, gelatina)?', ageGroup: '6-23', options: ['Sim', 'Não', 'Não Sabe'], answer: '' },

    // Perguntas para acima de 2 anos
    { id: 30, questionText: 'Você tem costume de realizar as refeições assistindo à TV, mexendo no computador e/ou celular?', ageGroup: '2+', options: ['Sim', 'Não', 'Não Sabe'], answer: '' },
    { id: 31, questionText: 'Quais refeições você faz ao longo do dia?', ageGroup: '2+', options: ['Café da manhã', 'Lanche da manhã', 'Almoço', 'Lanche da tarde', 'Jantar', 'Ceia'], answer: '' },
    { id: 32, questionText: 'Ontem, você consumiu Feijão?', ageGroup: '2+', options: ['Sim', 'Não', 'Não Sabe'], answer: '' },
    { id: 33, questionText: 'Ontem, você consumiu Frutas frescas (não considerar suco de frutas)?', ageGroup: '2+', options: ['Sim', 'Não', 'Não Sabe'], answer: '' },
    { id: 34, questionText: 'Ontem, você consumiu Verduras e/ou legumes (não considerar batata, mandioca, aipim, macaxeira, cará e inhame)?', ageGroup: '2+', options: ['Sim', 'Não', 'Não Sabe'], answer: '' },
    { id: 35, questionText: 'Ontem, você consumiu Hambúrguer e/ou embutidos (presunto, mortadela, salame, linguiça, salsicha)?', ageGroup: '2+', options: ['Sim', 'Não', 'Não Sabe'], answer: '' },
    { id: 36, questionText: 'Ontem, você consumiu Bebidas adoçadas (refrigerante, suco de caixinha, suco em pó, água de coco de caixinha, xaropes de guaraná/groselha, suco de fruta com adição de açúcar)?', ageGroup: '2+', options: ['Sim', 'Não', 'Não Sabe'], answer: '' },
    { id: 37, questionText: 'Ontem, você consumiu Macarrão instantâneo, salgadinhos de pacote ou biscoitos salgados?', ageGroup: '2+', options: ['Sim', 'Não', 'Não Sabe'], answer: '' },
    { id: 38, questionText: 'Ontem, você consumiu Biscoito recheado, doces ou guloseimas (balas, pirulitos, chiclete, caramelo, gelatina)?', ageGroup: '2+', options: ['Sim', 'Não', 'Não Sabe'], answer: '' },
  ];

  constructor(private dialog: MatDialog) {}

  openDialog(): void {
    const dialogRef = this.dialog.open(QuestionDialogComponent, {
      width: '80%',
      data: this.questions.filter(q => q.ageGroup === this.ageGroup)
    });

    dialogRef.afterClosed().subscribe(result => {
      if (result) {
        this.exportToXML(result);
      }
    });
  }

  exportToXML(questions: Question[]): void {
    let xmlString = '<?xml version="1.0" encoding="UTF-8"?><questions>';
    questions.forEach(question => {
      xmlString += `<question id="${question.id}"><questionText>${question.questionText}</questionText><answer>${question.answer}</answer></question>`;
    });
    xmlString += '</questions>';

    const blob = new Blob([xmlString], { type: 'application/xml' });
    const url = window.URL.createObjectURL(blob);
    const a = document.createElement('a');
    a.href = url;
    a.download = 'questions.xml';
    a.click();
    window.URL.revokeObjectURL(url);
  }
}
