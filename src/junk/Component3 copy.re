
type state = {
  canvasRef: ref(option(ReasonReact.reactRef))
};


let handleClick = (_event, self) => {
	Js.log("clicked!");
	Js.log(self.state);


	switch (self.state.canvasRef^) {
	|	None => ()
	|	Some(r) => self.state.canvasRef.fillRect( Canvas.getContext( self.state.canvasRef, "2d"), 0.0, 0.0, 100, 100);
	};
};

let setCanvasRef = (theRef, {ReasonReact.state}) => {
	self.state.canvasRef := Js.Nullable.toOption(theRef);
};

let component = ReasonReact.reducerComponent("CanvasThing");


let make = (_children) => {
	...component,
	initialState: () => {
    	{canvasRef: ()}
    },
	reducer: ((), _) => ReasonReact.NoUpdate,
	render: self =>
		<div onClick=(self.ReasonReact.handle(handleClick))>
			<canvas
				width="100"
				height="100"
				ref={self.ReasonReact.handle(setCanvasRef)}
			/>
		</div>,
};
