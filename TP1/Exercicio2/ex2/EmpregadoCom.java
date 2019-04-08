package ex2;


public class EmpregadoCom extends Funcionario {

	private double taxa_comissao;
	private int vendas;

	EmpregadoCom(String nome, String sobrenome, String nss,
		double taxa_comissao, int vendas){
		super(nome, sobrenome, nss);
		this.taxa_comissao = taxa_comissao;
		this.vendas = vendas;
	}

	public double getTaxaComissao(){
		return taxa_comissao;
	}
	public void setTaxaComissao(double taxa_comissao){
		this.taxa_comissao = taxa_comissao;
	}

	public int getVendas(){
		return vendas;
	}
	public void setVendas(int vendas){
		this.vendas = vendas;
	}

	public double salario() {
		return taxa_comissao*vendas;
	}

	public String toString(){
		return "Empregado Comissionado;\n"+super.toString()+
		"\nValor total das vendas: " +vendas+"\nTaxa de Comissão: "+
		taxa_comissao+"\nSalário Total: "+ salario();
	}

}