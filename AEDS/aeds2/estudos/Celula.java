public class Celula {
    public int elemento; //elemento
    public Celula prox; //referencia para proximo

    //Construtor
    public Celula() {
		this(0);
	}

	/**
	 * Construtor da classe.
	 * @param elemento int inserido na celula.
	 */
	public Celula(int elemento) {
        this.elemento = elemento;
        this.prox = null; //prox aponta para null
	}
}