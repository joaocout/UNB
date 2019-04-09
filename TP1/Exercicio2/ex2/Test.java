/*JOAO PEDRO ASSUNCAO COUTINHO - 180019813*/

package ex2;


public class Test {

	public static void main(String[] arguments){

		EmpregadoSalFixo joao = new EmpregadoSalFixo("João", "Silva", "129837", 1500.50);
		System.out.println(joao.toString()+ "\n");

		EmpregadoHoraExtra maria = new EmpregadoHoraExtra("Maria", "Ferreira", "122354", 200, 12);
		System.out.println(maria.toString() + "\n");

		EmpregadoCom pedro = new EmpregadoCom("Pedro", "Pereira", "990931", 0.10, 20000);
		System.out.println(pedro.toString() + "\n");

		EmpregadoCom ze = new EmpregadoSalCom("José", "Vieira", "747831", 0.10, 5000, 1000);
		System.out.println(ze.toString() + "\n");

		System.out.println(joao.salario());
		System.out.println(maria.salario());
		System.out.println(pedro.salario());
		System.out.println(ze.salario());

	}

}
