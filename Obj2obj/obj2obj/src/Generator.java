import org.antlr.v4.runtime.*;
import java.util.Scanner;
import java.util.Arrays;
import java.util.ArrayList;
import java.io.FileInputStream;
import java.io.FileNotFoundException;
import java.io.FileOutputStream;
import java.io.IOException;
import java.io.PrintStream;

import org.antlr.v4.runtime.tree.*;
import java.util.HashMap;

public class Generator extends ObjBaseListener {
  public static void main(String[] args) throws IOException { 
    ANTLRInputStream input = new ANTLRInputStream(new FileInputStream("H:\\CS455/Objects/water.obj"));
    ObjLexer lexer = new ObjLexer(input);
    CommonTokenStream tokens = new CommonTokenStream(lexer);
    ObjParser parser = new ObjParser(tokens);
    ParseTree tree = parser.file();

    ParseTreeWalker walker = new ParseTreeWalker();
    walker.walk(new Generator(), tree);
  }

  private ArrayList<Position> positions = new ArrayList<Position>();
  private ArrayList<TextureCoordinate> texcoords = new ArrayList<TextureCoordinate>();
  private ArrayList<Vertex> vertices = new ArrayList<Vertex>();
  private ArrayList<Face> faces = new ArrayList<Face>();
  private HashMap<Vertex, Integer> vertexToIndex = new HashMap<Vertex, Integer>();

  public void exitVertex(ObjParser.VertexContext context) {
    positions.add(new Position(Float.parseFloat(context.FLOAT(0).getText()),
                               Float.parseFloat(context.FLOAT(1).getText()),
                               Float.parseFloat(context.FLOAT(2).getText())));
  }

  public void exitTextureCoordinate(ObjParser.TextureCoordinateContext context) {
    texcoords.add(new TextureCoordinate(Float.parseFloat(context.FLOAT(0).getText()),
                                        Float.parseFloat(context.FLOAT(1).getText())));
  }

  public void exitFace(ObjParser.FaceContext context) {
    int[] indices = new int[3];
    for (int i = 0; i < 3; ++i) {
      int vi = Integer.parseInt(context.INT(i * 2).getText()) - 1;
      int ti = Integer.parseInt(context.INT(i * 2 + 1).getText()) - 1;
      Vertex vertex = new Vertex(vi, ti);
      Integer index = vertexToIndex.get(vertex);
      if (index != null) {
        indices[i] = index;
      } else {
        vertexToIndex.put(vertex, vertices.size());
        indices[i] = vertices.size();
        vertices.add(vertex);
      }
    }

    faces.add(new Face(indices[0], indices[1], indices[2]));
  }

  public void exitFile(ObjParser.FileContext context) {
    
	  PrintStream out = null;
	  try {
		out = new PrintStream("H:\\CS455/Objects/watertextured.obj");
	} catch (FileNotFoundException e) {
		// TODO Auto-generated catch block
		e.printStackTrace();
	}
	  
	out.println(vertices.size() + " " + faces.size());
    for (Vertex vertex : vertices) {
      Position p = positions.get(vertex.positionIndex);
      out.printf("v %f %f %f%n", p.x, p.y, p.z);
    }

    for (Vertex vertex : vertices) {
      TextureCoordinate t = texcoords.get(vertex.texcoordsIndex);
      out.printf("vt %f %f%n", t.u, t.v);
    }

    for (Face face : faces) {
      out.printf("f %d %d %d%n", face.a + 1, face.b + 1, face.c + 1);
    }
  }
}

class Position {
  public float x;
  public float y;
  public float z;

  public Position(float x, float y, float z) {
    this.x = x;
    this.y = y;
    this.z = z;
  }

  public String toString() {
    return String.format("%f %f %f", x, y, z);
  }
}

class TextureCoordinate {
  public float u;
  public float v;

  public TextureCoordinate(float u, float v) {
    this.u = u;
    this.v = v;
  }

  public String toString() {
    return String.format("%f %f", u, v);
  }
}

class Vertex {
  int positionIndex;
  int texcoordsIndex;

  public Vertex(int positionIndex, int texcoordsIndex) {
    this.positionIndex = positionIndex;
    this.texcoordsIndex = texcoordsIndex;
  }

  public String toString() {
    return String.format("%d/%d", positionIndex, texcoordsIndex);
  }

  public int hashCode() {
    return toString().hashCode();
  }

  public boolean equals(Object object) {
    Vertex ov = (Vertex) object;
    return positionIndex == ov.positionIndex && texcoordsIndex == ov.texcoordsIndex;
  }
}

class Face {
  int a, b, c;

  public Face(int a, int b, int c) {
    this.a = a;
    this.b = b;
    this.c = c;
  }
}
