
type state = {
  canvasRef: ref(option(Dom.element))
};


let component = ReasonReact.reducerComponent("CanvasThing");

let setCanvasRef = (theRef, {ReasonReact.state}) => {
	state.canvasRef := Js.Nullable.toOption(theRef);
};

let make = (_children) => {
	let handleClick = (_event, self: ReasonReact.self(state, ReasonReact.noRetainedProps, unit)) => {
		Js.log(self.state);

		switch (self.state.canvasRef^) {
			|	None => ()
			|	Some(r) => Canvas.fillRect( Canvas.getContext( r ), 0.0, 0.0, 100.0, 100.0);
		};
	};

	{
	...component,
	initialState: () => {
    	{canvasRef: ref(None)}
    },
	reducer: ((), _) => ReasonReact.NoUpdate,
	render: self =>
		<div onClick=(self.handle(handleClick))>
			<canvas
				width="100"
				height="100"
				ref={self.handle(setCanvasRef)}
			/>
		</div>,
	}
};
