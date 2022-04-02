import java.util.ArrayList;

public class Vidange {

    public static void main(String[] args) {
        //Creer la sequence d'elements a ouvrir
        System.out.println("Debut d'operation de vidange");

        Pile elements = new Pile();
        elements.ouvrir(new Element("capot"));
        elements.ouvrir(new Element("bouchon-haut du reservoir"));
        elements.ouvrir(new Element("bouchon-bas du reservoir"));
        elements.ouvrir(new Element("bouchon-boîte d’huile"));

        elements.toutFermer();
        System.out.println("Operation achevee");
    }

    public static class Element {
        private String description;

        public Element(String description) {
            this.description = description;
        }

        public String getDescription() {
            return description;
        }

        public void setDescription(String description) {
            this.description = description;
        }
    }

    public static class Pile {
        ArrayList<Element> liste;

        public Pile() {
            liste = new ArrayList<>();
        }

        /**
         * Simuler l'ouverture d'un element (example: capot) en l'ajoutant a la pile
         *
         * @param e
         */
        public void ouvrir(Element e) {
            System.out.println("Ouvrir le " + e.getDescription());
            liste.add(e);
        }

        /**
         * Simuler la fermeture d'un element dans l'ordre d'une pile
         */
        public void fermer() {
            if (!liste.isEmpty()) {
                Element dernierElement = liste.get(liste.size() - 1);
                System.out.println("Fermer le " + dernierElement.getDescription());
                liste.remove(liste.size() - 1);
            } else {
                System.out.println("Plus d'elements a fermer.");
            }
        }

        public void toutFermer() {
            while (!liste.isEmpty()) {
                fermer();
            }
        }
    }
}
