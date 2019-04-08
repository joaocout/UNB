package ex2;


public class EmpregadoHoraExtra extends EmpregadoSalFixo{

	private double valor_hr_extra;
	private double horas_extras;

	EmpregadoHoraExtra(String nome, String sobrenome, String nss, 
		double salario_base, double valor_hr_extra, double horas_extras){
		super(nome, sobrenome, nss, salario_base);
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
		return super.salario() + (horas_extras * valor_hr_extra);
	}

	public String toString(){
		return "Empregado com Salário e Hora Extra;\nNome: "+getNome()+"\nSobrenome: "+
		getSobrenome()+"\nNSS: "+getNSS()+"\nSalário Base: " + getSalarioBase()+"\nHoras Extras: "+
		horas_extras+"\nValor da Hora Extra: " +valor_hr_extra+"\nSalário Total: "+
		salario();
	}

}