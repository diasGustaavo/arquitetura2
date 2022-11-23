import 'dart:math';

class Aluno {
  int? mat;
  int? nota;

  Aluno(this.mat, this.nota);
}

void programaOtimizadoAdicionando(final int tam) {
  const matBase = 2019000;
  var alunos = [];
  for (var i = 0; i < tam; i++) {
    alunos.add(Aluno(matBase + i, Random().nextInt(10)));
  }
}

void programaNaoOtimizadoAdicionando(final int tam) {
  const matBase = 2019000;
  var mat = [];
  var nota = [];

  for (var i = 0; i < tam; i++) {
    mat.add(matBase + i);
  }

  for (var i = 0; i < tam; i++) {
    nota.add(Random().nextInt(10));
  }
}

void programaOtimizadoAlterando(final int tam) {
  const matBase = 2019000;
  var alunos = new List<Aluno>.generate(tam, (final int _) => Aluno(0, 0));

  for (var i = 0; i < tam; i++) {
    alunos[i].mat = matBase + i;
    alunos[i].nota = Random().nextInt(10);
  }
}

void programaNaoOtimizadoAlterando(final int tam) {
  const matBase = 2019000;
  var mat = new List<int>.filled(tam, 0);
  var nota = new List<int>.filled(tam, 0);

  for (var i = 0; i < tam; i++) {
    mat[i] = matBase + i;
  }

  for (var i = 0; i < tam; i++) {
    nota[i] = Random().nextInt(10);
  }
}

void main(List<String> args) {
  final Stopwatch s = new Stopwatch();

  var tamanhosArray = [10000, 1000000, 10000000, 100000000];
  tamanhosArray.forEach((tamanhoArray) {
    print('\n');
    s.start();
    programaNaoOtimizadoAdicionando(tamanhoArray);
    print(
        'tempo decorrido (programa nao otimizado adicionando no array $tamanhoArray): ${s.elapsedMilliseconds} milisegundos');
    s.reset();
    programaNaoOtimizadoAlterando(tamanhoArray);
    print(
        'tempo decorrido (programa nao otimizado alterando o array $tamanhoArray): ${s.elapsedMilliseconds} milisegundos');
    s.reset();
    programaOtimizadoAdicionando(tamanhoArray);
    print(
        'tempo decorrido (programa otimizado adicionando no array $tamanhoArray): ${s.elapsedMilliseconds} milisegundos');
    s.reset();
    programaOtimizadoAlterando(tamanhoArray);
    print(
        'tempo decorrido (programa otimizado alterando o array $tamanhoArray): ${s.elapsedMilliseconds} milisegundos');
    s.reset();
  });
}
