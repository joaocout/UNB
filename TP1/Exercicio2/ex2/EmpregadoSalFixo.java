package ex2;


public class EmpregadoSalFixo extends Funcionario{

	private double salario_base;

	EmpregadoSalFixo(String nome, String sobrenome, String nss, 
		double salario_base){
		super(nome, sobrenome, nss);
		this.salario_base = salario_base;
	}

	public double getSalarioBase(){
		return salario_base;
	}
	public void setSalarioBase(double salario_base){
		this.salario_base = salario_base;
	}

	public double salario(){
		return salario_base;
	}

	public String toString(){
		return "Empregado com salário fixo;\n" + super.toString() +
		 "\nSalário: " + salario();
	}

}