package ex2;


public class EmpregadoSalCom extends EmpregadoCom{

	private double salario_base;

	EmpregadoSalCom(String nome, String sobrenome, String nss, 
		double taxa_comissao, int vendas, double salario_base){
		super(nome, sobrenome, nss, taxa_comissao, vendas);
		this.salario_base = salario_base;
	}

	public double getSalarioBase(){
		return salario_base;
	}
	public void setSalarioBase(double salario_base){
		this.salario_base = salario_base;
	}

	public double salario(){
		return salario_base + super.salario();
	}
	public String toString(){
		return "Empregado com Salário e Comissão\nNome: "+ getNome()+
		"\nSobrenome: " + getSobrenome() +"\nNSS: "+getNSS() +"\nSalário Base: "+
		salario_base+"\nValor total das vendas: " +getVendas()+
		"\nTaxa de Comissão: "+getTaxaComissao()+"\nSalário Total: "+
		salario();
	}

}