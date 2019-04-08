package ex2;


public abstract class Funcionario{

	private String nome, sobrenome, nss;

	Funcionario(String nome, String sobrenome, String nss){
		this.nome = nome;
		this.sobrenome = sobrenome;
		this.nss = nss;
	}

	public String getNome() {
		return nome;
	}
	public void setNome(String nome) {
		this.nome = nome;
	}

	public String getSobrenome() {
		return sobrenome;
	}
	public void setSobrenome(String sobrenome) {
		this.sobrenome = sobrenome;
	}

	public String getNSS(){
		return nss;
	}
	public void setNSS(String nss){
		this.nss = nss;
	}

	public String toString(){
		return "Nome: "+nome+"\nSobrenome: "+sobrenome+"\nNSS: "+nss;
	}

	public abstract double salario();


}