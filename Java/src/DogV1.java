class DogV1 implements Comparable {
    String name;
    String breed;
    public DogV1(String name, String breed) {
        this.name = name;
        this.breed = breed;
    }
    @Override //When use the sort, you should use the compareTo function.
    public int compareTo(Object o) {
        DogV1 d=(DogV1)o;
        return this.name.compareTo(d.name);
    }
    @Override
    public String toString() {
        String msg=name+" "+breed;
        return msg;
    }
}
