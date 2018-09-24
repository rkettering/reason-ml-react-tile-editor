
type state = {
  canvasRef: ref(option(Dom.element))
};

type rect = {
	x: float,
	y: float,
	w: float,
	h: float,
}

let component = ReasonReact.reducerComponent("CanvasThing");

let setCanvasRef = (theRef, {ReasonReact.state}) => {
	state.canvasRef := Js.Nullable.toOption(theRef);
};


let get_mouse_pos_for_action = ( event, ref ) => {
	Js.log(event);


	let bgRectSrc:Dom.domRect = Canvas.getBoundingClientRect(ref);
	let bgRect:rect = { x: bgRectSrc.left, y: bgRectSrc.top, w: bgRectSrc.right - bgRectSrc.left, h: bgRectSrc.bottom - bgRectSrc.top };

	Js.log(bgRect);
	
};



let make = (_children) => {
	let handleClick = (event, self: ReasonReact.self(state, ReasonReact.noRetainedProps, unit)) => {
		/* Js.log(self.state); */

		switch (self.state.canvasRef^) {
			|	None => ()
			|	Some(r) => {
					get_mouse_pos_for_action(event, r);
					Canvas.fillRect( Canvas.getContext( r ), 0.0, 0.0, 100.0, 100.0);
				}
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
