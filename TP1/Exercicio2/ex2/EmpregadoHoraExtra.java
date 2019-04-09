package ex2;


public class EmpregadoHoraExtra extends Funcionario{

	private double valor_hr_extra;
	private double horas_extras;

	EmpregadoHoraExtra(String nome, String sobrenome, String nss, 
		double valor_hr_extra, double horas_extras){
		super(nome, sobrenome, nss);
		this.valor_hr_extra = valor_hr_extra;
		this.horas_extras = horas_extras;
	}

	public double getValorHrExtra(){
		return valor_hr_extra;
	}
	public void setValorHrExtra(double valor_hr_extra){
		this.valor_hr_extra = valor_hr_extra;
	}

	public double getHorasExtras(){
		return horas_extras;
	}
	public void setHorasExtras(double horas_extras){
		this.horas_extras = horas_extras;
	}

	public double salario(){
		return (horas_extras * valor_hr_extra);
	}

	public String toString(){
		return "Empregado com Hora Extra;\nNome: "+getNome()+"\nSobrenome: "+
		getSobrenome()+"\nNSS: "+getNSS()+"\nHoras Extras: "+
		horas_extras+"\nValor da Hora Extra: " +valor_hr_extra+"\nSalário Total: "+
		salario();
	}

}