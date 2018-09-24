type state = {
  canvasRef: ref(option(ReasonReact.reactRef))
};

type action =
  | Click;


let handleClick = (self, state) => {
	Js.log("clicked!");
	Js.log(self);

	ReasonReact.Update(state);
};

let component = ReasonReact.reducerComponent("CanvasThing");


let make = (_children) => {
	...component,
	initialState: () => {
    	{canvasRef: ref(None)}
    },
	reducer: (action, state) =>
    	switch (action) {
    	| Click =>
			handleClick(self, state)
    },

	render: (self) =>
		<div onClick=(_event => self.send( Click ))>
		</div>

};
