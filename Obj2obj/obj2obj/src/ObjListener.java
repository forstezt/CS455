// Generated from Obj.g4 by ANTLR 4.0
import org.antlr.v4.runtime.tree.*;
import org.antlr.v4.runtime.Token;

public interface ObjListener extends ParseTreeListener {
	void enterTextureCoordinate(ObjParser.TextureCoordinateContext ctx);
	void exitTextureCoordinate(ObjParser.TextureCoordinateContext ctx);

	void enterFile(ObjParser.FileContext ctx);
	void exitFile(ObjParser.FileContext ctx);

	void enterLine(ObjParser.LineContext ctx);
	void exitLine(ObjParser.LineContext ctx);

	void enterVertex(ObjParser.VertexContext ctx);
	void exitVertex(ObjParser.VertexContext ctx);

	void enterFace(ObjParser.FaceContext ctx);
	void exitFace(ObjParser.FaceContext ctx);
}