module FormErrors = {
  [@react.component]
  let make = (~formRules: FormTypes.formRules) =>
    <div>
      <ul>
        {Belt.Array.map(formRules, rule =>
           <li
             key={rule.id |> string_of_int}
             className={
               rule.valid
                 ? "is-success help is-size-6" : "is-danger help is-size-6"
             }>
             <i className={rule.valid ? "fas fa-check" : "fas fa-times"} />
             {" " |> React.string}
             {rule.message |> React.string}
           </li>
         )
         |> React.array}
      </ul>
    </div>;
};

[@react.component]
let make = (~formType) => {
  // let (state, dispatch) = React.useReducer(reducer, initialState);
  /* we will pass this as our callback */
  let logger = () => Js.log("Form submitted");

  let (state, formRules, handleChange, handleSubmit) =
    UseForm.useForm(~formType, ~callback=logger);
  let formType =
    switch (formType) {
    | Register => "Register"
    | Login => "Login"
    };
  <div className="section is-fullheight">
    <div className="container">
      <div className="column is-4 is-offset-4">
        <h1 className="is-size-1 has-text-centered is-capitalized">
          {formType |> React.string}
        </h1> // (A)
        <br />
        {switch (formRules) {
         | [||] => React.null
         | _ => <FormErrors formRules />
         }}
        <br />
        <div className="box">
          <form onSubmit=handleSubmit>
            {formType === "register"
               // (C)
               ? <div className="field">
                   <label className="label">
                     {"Username" |> React.string}
                   </label>
                   <div className="control">
                     <input
                       className="input"
                       type_="text"
                       name="username"
                       value={state.username}
                       required=true
                       onChange=handleChange // (D)
                     />
                   </div>
                 </div>
               : React.null}
            <div className="field">
              <label className="label">
                {"Email Address" |> React.string}
              </label>
              <div className="control">
                <input
                  className="input"
                  type_="email"
                  name="email"
                  value={state.email}
                  required=true
                  onChange=handleChange
                />
              </div>
            </div>
            <div className="field">
              <label className="label"> {"Password" |> React.string} </label>
              <div className="control">
                <input
                  className="input"
                  type_="password"
                  name="password"
                  value={state.password}
                  required=true
                  onChange=handleChange
                />
              </div>
            </div>
            <button
              type_="submit"
              className="button is-block is-info is-fullwidth is-uppercase">
              {formType |> React.string} // (A)
              <br />
            </button>
          </form>
        </div>
      </div>
    </div>
  </div>;
};
